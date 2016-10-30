#include "include/nenuphar/surfEtat/Grand.hpp"
#include "include/nenuphar/surfEtat/Moyen.hpp"

#include "include/nenuphar/Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const Grand Grand::_grand; 

            SurfEtat const* Grand::getInstance(){
                return &_grand;
            }

            void Grand::age(Surface& victim)const{
                victim.setEtat(Moyen::getInstance());    
            }

            const std::string Grand::nomEtat()const{
                return "Grand";
            }
        }
        
    }
}
