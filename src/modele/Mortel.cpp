#include "Mortel.hpp"
#include "Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void Mortel::souffrir(froppie::Froppie& victim)const{
                victim.setMort();
            }

            const std::string Mortel::nomStrategy()const{
                return "Mortel";
            }
        }
        
    }
}
