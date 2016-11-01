#include "Self.hpp"

namespace froppieLand{
    namespace modele{

        const Self Self::_self();

        Self::Self(){
            
        }

        const Self& getSelf()const{
            return _self;
        }

        const int Self::getVectorXDirection()const{
            return 0;
        }
        const int Self::getVectorYDirection()const{
            return 0;
        }
    }
}