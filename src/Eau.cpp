#include "include/Eau.hpp"

namespace froppieLand{
    namespace modele{
        void Eau::souffrir(Froppie& victim)const {
            victim.getCurEtat().setMort(victim);
        }
    }
}
