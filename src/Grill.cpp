#include <math.h>

#include "include/Grill.hpp"
#include "include/FroppieMoveObserver.hpp"

namespace froppieLand{
    namespace modele{
        Grill::Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA):
            _taille(taille), _depart({posXD, posYD}), _arrivee({posXA, posYA})
        {
            _terrain = new Surface[taille];
            for(int i = 0 ; i < taille ; i++){
                _terrain[i] = new Surface[taille];
            }

            for(unsigned int i = 0; i < taille ; i++){
                for(unsigned int j = 0 ; i < taille ; j++){
                    _terrain[i][j] = new Surface(i, j);
                }
            }

            _froppie = new Froppie(10, _depart);
            _froppie.addMoveObersver(this);
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

        void Grill::vieillissemet() const{
            for(int i = 0 ; i < _taille ; i++){
                for(int j = 0 ; j < _taille ; j++){
                    _terrain[i][j]->vieillissement();
                }
            }
        }

        void Grill::consChemin()const{

            Position& fropPosition = froppie->getPosition();
            if(fropPosition.X == _arrivee.X){
                for(int i = 0 ; i < math.abs(_arrivee.Y - fropPosition.Y) ; i++){
                    _terrain[fropPosition.X][i]->nouvNenu();
                }
            }
            else if(fropPosition.Y == _arrive.Y){
                for(int i = 0 ; i < math.abs(_arrivee.X - fropPosition.Y) ; i++){
                    _terrain[i][fropPosition.Y]->nouvNenu();
                }
            }
            else{
                for(int i = 0 ; i < math.abs(_arrivee.X - fropPosition.X) ; i++){
                    for(int j = 0 ; j < math.abs(_arrivee.Y - fropPosition.Y) ; j++){
                        _terrain[i][j]->nouvNenu();
                    }
                }
            }
        }

        void Grill::notifyMove(){

            Position currPos = _froppie->getPosition();
            (*_terrain[currPos.X, currPos.Y])->souffrir(&_froppie);
        }
    }
}


