#include "include/nenuphar/surfEtat/Petit.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            SurfEtat& Petit::getInstance(){
                if(Petit::_instance)
                    Petit::_instance = new Petit();
                return *Petit::_instance;
            }
            const SurfEtat& Petit::age()const{
                return Inexistant::getInstance();
            }

            const std::string& nomEtat()const{
                return "Petit";
            }
        }
        
    }
}
