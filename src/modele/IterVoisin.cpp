#include "IterVoisin.hpp"

#include "Nord.hpp"
#include "Sud.hpp"
#include "Est.hpp"
#include "Ouest.hpp"
#include "Self.hpp"


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
                :_surfPos(positionTest), _voisinPotentiel(nullptr), _currentIndex(0), _directionActuelle(&modele::Self::getSelf()){
            }

            const Direction& IterVoisin::getDirectionActuelle()const{
                return *_directionActuelle;
            }

            bool IterVoisin::isFini()const{
                return _currentIndex == _directions.size();
            }

            bool IterVoisin::voisinSuivant(){
                unsigned int index = _currentIndex++;
                bool isVoisin = _surfPos.getLigne() + _directions[index]->getVectorYDirection() == _voisinPotentiel->getLigne()
                        &&
                        _surfPos.getColonne() + _directions[index]->getVectorXDirection() == _voisinPotentiel->getColonne();
            
                if(isVoisin)
                {
                    _directionActuelle = _directions[index];
                }

                return isVoisin;
            }

            void IterVoisin::setVoisinPotentiel(unsigned int& ligne, unsigned int& colonne){
                _voisinPotentiel.reset(new Position(ligne, colonne));
                _currentIndex = 0;
            }

        }
    }
}