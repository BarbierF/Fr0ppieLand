#include "include/nenuphar/strategy/Eau.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void Eau::souffrir(Froppie& victim)const {
                victim.setMort();
            }

            const string& nomStrategy()const{
                return "Eau";
            }
        }
        
    }
}
