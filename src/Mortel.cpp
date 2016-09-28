#include "include/Mortel.hpp"

namespace froppieLand{
    namespace modele{
        void Mortel::souffrir(Froppie& victim)const{
            victim.setMort();
        }
    }
}
