#include "Petit.hpp"
#include "Inexistant.hpp"

#include "Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            const Petit Petit::_petit;

            SurfEtat const* Petit::getInstance(){
                return &_petit;
            }
            void Petit::age(Surface& victim)const{
                victim.setEtat(Inexistant::getInstance());
                victim.setStrategy(FactoryStrategyNenuphar::getStrategy(Surface::TypeNenu::eau));
            }

            const std::string Petit::nomEtat()const{
                return "Petit";
            }
        }
        
    }
}
