#include "include/nenuphar/strategy/Nutritif.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            void Nutritif::souffrir(Froppie& victim)const{
                victim.setSain();
                victim.doper();
            }

            const string& Nutritif::nomStrategy()const{
                return "Nutritif";
            }
        }
        
    }
}
