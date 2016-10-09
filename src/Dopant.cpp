#include "include/Dopant.hpp"

namespace froppieLand{
    namespace modele{
        void Dopant::souffrir(Froppie& victim)const{
            victim.setSain();
            victim.doper();
        }
    }
}
