#include "include/nenuphar/strategy/Veneneux.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            void Veneneux::souffrir(Froppie& victim)const{
                victim.setMalade();
                victim.subir();
            }

            const string& Veneneux::nomStrategy()const{
                return "Veneneux";
            }
        }
        
    }
}
