#include "Dopant.hpp"
#include "Froppie.hpp"

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
