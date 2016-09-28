#include "include/Nutritif.hpp"

namespace froppieLand{
    namespace modele{
        void Nutritif::souffrir(Froppie& victim)const{
            victim.setSain();
            victim.increaseHealth();
        }
    }
}
