#include "include/Veneneux.hpp"

namespace froppieLand{
    namespace modele{
        void Veneneux::souffrir(Froppie& victim)const{
            victim.setMalade();
            victim.subir();
        }
    }
}
