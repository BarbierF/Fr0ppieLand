#include "Nord.hpp"

namespace froppieLand{

    namespace modele{

        const Nord Nord::_nord;

        Nord::Nord(){
            
        }

        const Nord& Nord::getNord(){
            return _nord;
        }

        const int Nord::getVectorXDirection()const{
            return 0;
        }
        const int Nord::getVectorYDirection()const{
            return 1;
        }
    }
}