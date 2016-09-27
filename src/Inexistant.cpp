#include "include/Inexistant.hpp"

namespace froppieLand{
    namespace modele{
        SurfEtat& Inexistant::getInstance(){
            if(!Inexistant::_instance)
                Inexistant::_instance = new Inexistant();
            return *Inexistant::_instance;
        }
        const SurfEtat& Inexistant::age()const{
            return *this;
        }
    }
}
