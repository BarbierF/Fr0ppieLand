#include "include/Ouest.hpp"

namespace froppieLand{

    namespace modele{

        const Ouest Ouest::_ouest;

        Ouest::Ouest(){
            
        }

        const Ouest& Ouest::getOuest(){
            return _ouest;
        }

        const int Ouest::getVectorXDirection()const{
            return -1;
        }
        const int Ouest::getVectorYDirection()const{
            return 0;
        }
    }
}