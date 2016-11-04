#include "include/nenuphar/strategy/Dopant.hpp"
#include "include/froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void Dopant::souffrir(froppie::Froppie& victim)const{
                victim.setSain();
                victim.doper();
            }

            const std::string Dopant::nomStrategy()const{
                return "Dopant";
            }
        }
        
    }
}
