#include "include/nenuphar/surfEtat/Petit.hpp"
#include "include/nenuphar/surfEtat/Inexistant.hpp"

#include "include/nenuphar/Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const Petit Petit::_petit;

            SurfEtat const* Petit::getInstance(){
                return &_petit;
            }
            void Petit::age(Surface& victim)const{
                victim.setEtat(Inexistant::getInstance());
            }

            const std::string Petit::nomEtat()const{
                return "Petit";
            }
        }
        
    }
}
