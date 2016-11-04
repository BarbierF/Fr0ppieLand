#include "Veneneux.hpp"
#include "Froppie.hpp"

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
