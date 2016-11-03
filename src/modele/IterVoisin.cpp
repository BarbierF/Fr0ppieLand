#include "include/modele/nenuphar/IterVoisin.hpp"

#include "include/modele/directions/Nord.hpp"
#include "include/modele/directions/Sud.hpp"
#include "include/modele/directions/Est.hpp"
#include "include/modele/directions/Ouest.hpp"


namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const std::vector IterVoisin::_direction{
                Nord::getNord(),
                Sud::getSud(),
                Ouest::getOuest(),
                Est::getEst()
            };

            IterVoisin::IterVoisin(const Position& positionTest, const Position& voisinPotentiel)
                :_surfPos(positionTest), _voisinPotentiel(voisinPotentiel){
                    _currentIndex = 0;
            }

            const Direction& IterVoisin::getDirectionActuelle()const{
                return _directions[currentIndex];
            }

            bool IterVoisin::isFini(){
                return _currentIndex == _directions.size();
            }

            bool IterVoisin::voisinSuivant()const{
                unsigned int index = _currentIndex++;

                return  _position.X + _direction[index] == _voisinPotentiel.X
                        &&
                        _position.Y + _direction[index] == _voisinPotentiel.Y;
            }

            void IterVoisin::setVoisinPotentiel(const Position& voisinPotentiel){
                delete _voisinPotentiel;
                _voisinPotentiel = &voisinPotentiel;
            }

            void IterVoisin::reset(){
                _currentIndex = 0;
            }
        }
    }
}