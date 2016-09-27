#include "include/Petit.hpp"
#include "include/Inexistant.hpp"

namespace froppieLand{
    namespace modele{
        SurfEtat& Petit::getInstance(){
            if(Petit::_instance)
                Petit::_instance = new Petit();
            return *Petit::_instance;
        }
        const SurfEtat& Petit::age()const{
            return Inexistant::getInstance();
        }
    }
}
