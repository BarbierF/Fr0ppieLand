#include "include/nenuphar/strategy/Eau.hpp"
#include "include/froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void Eau::souffrir(froppie::Froppie& victim)const {
                victim.setMort();
            }

            const std::string Eau::nomStrategy()const{
                return "Eau";
            }
        }
        
    }
}
