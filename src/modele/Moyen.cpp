#include "include/nenuphar/surfEtat/Moyen.hpp"
#include "include/nenuphar/surfEtat/Petit.hpp"

#include "include/nenuphar/Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const Moyen Moyen::_moyen;

            SurfEtat const* Moyen::getInstance(){
                return &_moyen;
            }
            void Moyen::age(Surface& victim)const{
                victim.setEtat(Petit::getInstance());
            }

            const std::string Moyen::nomEtat()const{
                return "Moyen";
            }
        }
        }
        
}
