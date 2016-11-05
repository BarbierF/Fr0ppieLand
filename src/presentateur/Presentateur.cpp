#include "Presentateur.hpp"


namespace froppieLand{
    namespace presentateur{

        Presentateur::Presentateur(const unsigned int taille
            , const unsigned int depX, const unsigned int depY
            , const unsigned int arrX, const unsigned int arrY
            , const unsigned int& resoMin, const unsigned int& resoMax
            , unsigned int& tempsPartie, unsigned int& tempsVieillissement)
            : _vue(new FroppieVue(*this))
            , _modele(new Grill(taille, depX, depY, arrX, arrY))
            , _tempsPartie(tempsPartie)
            , _tempsVieillissement(tempsVieillissement)
            , _resoMin(resoMin), _resoMax(resoMax){

            

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

            return _ligne == arrivee.X && _colonne == arrivee.Y;
        }

        bool Presentateur::isPossibleMove(const unsigned int ligne, const unsigned int colonne){
            
            Grill::Surface froppieSurf = _modele->getModifFroppieSurf();
            return froppieSurf.isCaseVoisine(ligne, colonne);

        }

        bool Presentateur::isFroppied(const unsigned int& ligne, const unsigned int& colonne)const{
            const Froppie& froppie = _modele->getFroppie();
            const Position& froPosition = froppie.getPosition();

            return ligne == froPosition.X && ligne == froPosition.Y;
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