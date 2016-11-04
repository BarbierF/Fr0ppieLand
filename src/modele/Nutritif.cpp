#include "include/nenuphar/strategy/Nutritif.hpp"
#include "include/froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            void Nutritif::souffrir(froppie::Froppie& victim)const{
                victim.setSain();
                victim.doper();
            }

            const std::string Nutritif::nomStrategy()const{
                return "Nutritif";
            }
        }
        
    }
}
