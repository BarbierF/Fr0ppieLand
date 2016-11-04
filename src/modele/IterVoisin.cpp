#include "include/nenuphar/IterVoisin.hpp"

#include "include/directions/Nord.hpp"
#include "include/directions/Sud.hpp"
#include "include/directions/Est.hpp"
#include "include/directions/Ouest.hpp"


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

                return  _surfPos.X + _directions[index]->getVectorXDirection() == _voisinPotentiel->X
                        &&
                        _surfPos.Y + _directions[index]->getVectorYDirection() == _voisinPotentiel->Y;
            }

            void IterVoisin::setVoisinPotentiel(const Position& voisinPotentiel){
                if(_voisinPotentiel != nullptr) delete _voisinPotentiel;
                _voisinPotentiel = &voisinPotentiel;
            }

            void IterVoisin::reset(){
                _currentIndex = 0;
            }
        }
    }
}