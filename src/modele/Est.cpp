#include "Est.hpp"

namespace froppieLand{

    namespace modele{

        const Est Est::_est;

        Est::Est(){
            
        }

        const Est& Est::getEst(){
            return _est;
        }

        const int Est::getVectorXDirection()const{
            return -1;
        }
        const int Est::getVectorYDirection()const{
            return 0;
        }
    }
}