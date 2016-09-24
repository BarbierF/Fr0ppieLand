#include "Grill.hpp"

namespace froppieLand{
    namespace modele{
        Grill::Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA):
            _taille(taille), _depart({posXD, posYD}), _arrivee({posXA, posYA})
        {
            _terrain = new Surface[taille];
            for(int i = 0 ; i < taille ; i++){
                _terrain = new Surface[taille];
            }

            for(unsigned int i = 0; i < taille ; i++){
                for(unsigned int j = 0 ; i < taille ; j++){
                    _terrain[i][j] = new Surface(i, j);
                }
            }
        }

        const Position& Grill::getDepart()const{
            return _depart;
        } 
        const Position& Grill::getArrivee()const{
            return _arrivee;
        }
        Froppie& Grill::getFroppie()const{
            return Froppie;
        }
        const Surface& Grill::getCase(unsigned int X, unsigned int Y){
            return _terrain[X][Y];
        }
    }
}


