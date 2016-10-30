#include "include/directions/Sud.hpp"

namespace froppieLand{

    namespace modele{

        const Sud Sud::_sud;

        Sud::Sud(){
            
        }

        const Sud& Sud::getSud(){
            return _sud;
        }

        const int Sud::getVectorXDirection()const{
            return 0;
        }
        const int Sud::getVectorYDirection()const{
            return -1;
        }
    }
}