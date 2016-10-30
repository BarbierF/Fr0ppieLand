#include "include/nenuphar/strategy/Mortel.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void Mortel::souffrir(Froppie& victim)const{
                victim.setMort();
            }

            const string& Mortel::nomStrategy()const{
                return "Mortel";
            }
        }
        
    }
}
