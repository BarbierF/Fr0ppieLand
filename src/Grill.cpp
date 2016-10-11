#include <cmath>

#include "include/Grill.hpp"
#include "include/FroppieMoveObserver.hpp"


namespace froppieLand{
    namespace modele{
        Grill::Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA):
            _taille(taille), _depart({posXD, posYD}), _arrivee({posXA, posYA})
        {
            _terrain.reserve(_taille * _taille);

            _froppie = new Froppie(10, _depart.X, _depart.Y);
            _froppie->addMoveObserver(this);
        }

        const Position& Grill::getDepart()const{
            return _depart;
        } 
        const Position& Grill::getArrivee()const{
            return _arrivee;
        }
        Froppie& Grill::getFroppie()const{
            return *_froppie;
        }
        const Surface& Grill::getCase(unsigned int X, unsigned int Y)const{
            return *_terrain[X * _taille + Y];
        }

        void Grill::vieilissement(){
            for(int i = 0 ; i < _taille ; i++){
                for(int j = 0 ; j < _taille ; j++){
                    _terrain[i * _taille + j]->age();
                }
            }
        }

        void Grill::consChemin()const{

            const Position& fropPosition = _froppie->getPosition();
            if(fropPosition.X == _arrivee.X){
                for(int i = 0 ; i < std::abs(_arrivee.Y - fropPosition.Y) ; i++){
                    _terrain[fropPosition.X * _taille + i]->nouvNenu();
                }
            }
            else if(fropPosition.Y == _arrivee.Y){
                for(int i = 0 ; i < std::abs(_arrivee.X - fropPosition.Y) ; i++){
                    _terrain[i * _taille + fropPosition.Y]->nouvNenu();
                }
            }
            else{
                for(int i = 0 ; i < std::abs(_arrivee.X - fropPosition.X) ; i++){
                    for(int j = 0 ; j < std::abs(_arrivee.Y - fropPosition.Y) ; j++){
                        _terrain[i * _taille + j]->nouvNenu();
                    }
                }
            }
        }

        void Grill::notifyMove()const{

            Position currPos = _froppie->getPosition();
            _terrain[currPos.X * _taille + currPos.Y]->souffrir(*_froppie);
        }
    }
}


