#include "include/Presentateur.hpp"


namespace froppieLand{
    namespace vue{

        Presentateur::Presentateur(FroppieVue& vue, Grill& modele
        , const unsigned int taille
        , const unsigned int depX, const unsigned int depY
        , const unsigned int arrX, const unsigned int arrY
        , const unsigned int resoMin, const unsigned int resoMax
        , unsigned int tempsPartie, const unsigned int tempsVieillissement)
            : _vue(vue), _modele(taille, depX, depY, arrX, arrY)
            , _tempsPartie(tempsPartie)
            , _tempsVieillissement(tempsVieillissement){

            

        }

        const unsigned int& Presentateur::getTempsPartie()const{
            return _tempsPartie;
        }

        const unsigned int& Presentateur::getTempsVieillissement()const{
            return _tempsVieillissement:
        }

        const unsigned int& Presentateur::getResolutionMin()const{
            return _resoMin;
        }

        const unsigned int& Presentateur::getResolutionMax()const{
            return _resoMax;
        }

        bool Presentateur::isArrived(const unsigned int& _ligne, const unsigned int& _colonne)const{
            Position arrivee;

            return _ligne == arrivee.X && _colonne == arrivee.Y;
        }

        bool Presentateur::isPossibleMove(const unsigned int& ligne, const unsigned int& colonne)const{
            
            Grill::Surface froppieSurf = _modele.getFroppieSurf();

            return froppieSurf.isCaseVoisine(Position(ligne, colonne));

        }

        const Direction& getDerniereDireFroppieVoisin()const{
            
            Grill::Surface froppieSurf = _modele.getFroppieSurf();

            return froppieSurf.getDirectionVoisin();
        }

        const int& getVieFroppie()const{
            return _modele.getFroppie().getPDV();
        }
    }
}