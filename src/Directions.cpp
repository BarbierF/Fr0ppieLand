#include "include/Directions.hpp"


namespace froppieLand{
    namespace modele{
        const int Nord::getVectorXDirection()const{
            return 0;
        }
        const int Nord::getVectorYDirection()const{
            return 1;
        }

        const int Sud::getVectorXDirection()const{
            return 0;
        }
        const int Sud::getVectorYDirection()const{
            return -1;
        }

        const int Ouest::getVectorXDirection()const{
            return 1;
        }
        const int Ouest::getVectorYDirection()const{
            return 0;
        }

        const int Est::getVectorXDirection()const{
            return -1;
        }
        const int Est::getVectorYDirection()const{
            return 0;
        }
    }
}

