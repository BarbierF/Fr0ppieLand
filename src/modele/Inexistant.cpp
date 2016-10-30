#include "include/nenuphar/surfEtat/Inexistant.hpp"

#include "include/nenuphar/Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const Inexistant Inexistant::_inexistant;

            SurfEtat const* Inexistant::getInstance(){
                return &_inexistant;
            }

            void Inexistant::age(Surface& victim)const{

            }

            const std::string Inexistant::nomEtat()const{
                return "Inexistant";
            }
        }
        


    }
}
