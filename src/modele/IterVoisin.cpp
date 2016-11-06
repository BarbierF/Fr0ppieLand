#include "IterVoisin.hpp"

#include "Nord.hpp"
#include "Sud.hpp"
#include "Est.hpp"
#include "Ouest.hpp"


namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const std::vector< modele::Direction const* > IterVoisin::_directions{
                &modele::Nord::getNord(),
                &modele::Sud::getSud(),
                &modele::Ouest::getOuest(),
                &modele::Est::getEst()
            };

            IterVoisin::IterVoisin(const Position& positionTest)
                :_surfPos(positionTest), _voisinPotentiel(nullptr){
                    _currentIndex = 0;
            }

            const Direction& IterVoisin::getDirectionActuelle()const{
                return *_directions[_currentIndex];
            }

            bool IterVoisin::isFini()const{
                return _currentIndex == _directions.size();
            }

            bool IterVoisin::voisinSuivant(){
                unsigned int index = _currentIndex++;

                return  _surfPos.getLigne() + _directions[index]->getVectorXDirection() == _voisinPotentiel->getLigne()
                        &&
                        _surfPos.getColonne() + _directions[index]->getVectorYDirection() == _voisinPotentiel->getColonne();
            }

            void IterVoisin::setVoisinPotentiel(unsigned int& ligne, unsigned int& colonne){
                _voisinPotentiel.reset(new Position(ligne, colonne));
            }

            void IterVoisin::reset(){
                _currentIndex = 0;
            }
        }
    }
}