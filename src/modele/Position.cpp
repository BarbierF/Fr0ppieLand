#include "Position.hpp"

namespace froppieLand{
    namespace modele{

        Position::Position(unsigned int& ligne, unsigned int& colonne)
            : _ligne(ligne), _colonne(colonne){
            
        }

        Position::Position(const unsigned int& ligne, const unsigned int& colonne)
            : _ligne(ligne), _colonne(colonne){

            }

        void Position::changeValue(const Direction& direction){
            _ligne += direction.getVectorYDirection();
            _colonne += direction.getVectorXDirection();
        }

        const unsigned int& Position::getLigne()const{
            return _ligne;
        }

        const unsigned int& Position::getColonne()const{
            return _colonne;
        }

        bool Position::operator<(const Position& o)const{

            if(_ligne == o.getLigne()){
                return _colonne < o.getColonne();
            }

            return _ligne < o.getLigne();
        }

    }
}