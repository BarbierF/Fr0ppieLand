#include "include/nenuphar/strategy/Veneneux.hpp"
#include "include/froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            void Veneneux::souffrir(froppie::Froppie& victim)const{
                victim.setMalade();
                victim.subir();
            }

            const std::string Veneneux::nomStrategy()const{
                return "Veneneux";
            }
        }
        
    }
}
