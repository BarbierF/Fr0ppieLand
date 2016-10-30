#include "include/nenuphar/strategy/Dopant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void Dopant::souffrir(Froppie& victim)const{
                victim.setSain();
                victim.doper();
            }

            const string& nomStrategy()const{
                return "Dopant";
            }
        }
        
    }
}
