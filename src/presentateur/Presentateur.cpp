#include "Presentateur.hpp"
#include <iostream>


namespace froppieLand{
    namespace presentateur{

        Presentateur::Presentateur(unsigned int taille
            , unsigned int depX, unsigned int depY
            , unsigned int arrX, unsigned int arrY
            , unsigned int resoMin, unsigned int resoMax
            , unsigned int tempsPartie, unsigned int tempsVieillissement)
            : _modele(new Grill(taille, depX, depY, arrX, arrY))
            , _vue(new FroppieVue(*this))
            , _resoMin(resoMin), _resoMax(resoMax)
            , _tempsPartie(tempsPartie)
            , _tempsVieillissement(tempsVieillissement)
            {

            

        }

        const unsigned int& Presentateur::getTempsPartie()const{
            return _tempsPartie;
        }

        const unsigned int& Presentateur::getTempsVieillissement()const{
            return _tempsVieillissement;
        }

        const unsigned int& Presentateur::getResolutionMin()const{
            return _resoMin;
        }

        const unsigned int& Presentateur::getResolutionMax()const{
            return _resoMax;
        }

        const unsigned int& Presentateur::getDimension()const{
            return _modele->getTaille();
        }

        bool Presentateur::isArrived(const unsigned int& _ligne, const unsigned int& _colonne)const{
            Position arrivee = _modele->getArrivee();

            return _ligne == arrivee.getLigne() && _colonne == arrivee.getColonne();
        }

        bool Presentateur::isPossibleMove(const unsigned int ligne, const unsigned int colonne){
            
            Grill::Surface froppieSurf = _modele->getModifFroppieSurf();

            return froppieSurf.isCaseVoisine(ligne, colonne);
        }

        bool Presentateur::isFroppied(const unsigned int& ligne, const unsigned int& colonne)const{
            const Froppie& froppie = _modele->getFroppie();
            const Position& froPosition = froppie.getPosition();

            return ligne == froPosition.getLigne() && colonne == froPosition.getColonne();
        }

        const Presentateur::Direction& Presentateur::getDerniereDireFroppieVoisin()const{
            
            Grill::Surface froppieSurf = _modele->getModifFroppieSurf();

            return froppieSurf.getDirectionVoisin();
        }

        const int& Presentateur::getVieFroppie()const{
            return _modele->getFroppie().getPDV();
        }

        std::string Presentateur::getTypeNenu(
            const unsigned int& ligne, const unsigned int& colonne
        )const{               
                return _modele->getSurface(ligne, colonne).getStrategy().nomStrategy();
        }

        std::string Presentateur::getEtatNenu(
            const unsigned int& ligne, const unsigned int& colonne
        )const{
            return _modele->getSurface(ligne, colonne).getEtat().nomEtat();
        }

        std::string Presentateur::getEtatFroppie()const{
            const Froppie& froppie = _modele->getFroppie();

            return froppie.getEtat().nomEtat();
        }

        Presentateur::FroppieVue* Presentateur::getVue(){
            return _vue.get();
        }

        void Presentateur::OMGFroppieIsGettingEaten(){
            Froppie& froppie = _modele->getModifFroppie();
            froppie.getEtat().setMort(froppie);
        }

        void Presentateur::deplaceFroppie(const Direction& directionDep){

            _modele->getModifFroppie().deplacer(directionDep);
        }

        void Presentateur::vieillirCase(
            const unsigned int& ligne, const unsigned int& colonne
        ){
            _modele->getSurfaceModifiable(ligne, colonne).age();  
        }

        void Presentateur::nouveauJeu(unsigned int resolution){

            _modele.reset(new Grill(resolution, 10, 0, 0, 10));
        }

    }
}