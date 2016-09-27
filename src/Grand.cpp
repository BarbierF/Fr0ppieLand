#include "include/Grand.hpp"
#include "include/Moyen.hpp"

namespace froppieLand{
    namespace modele{
        SurfEtat& Grand::getInstance(){
            if(!Grand::_instance)
                Grand::_instance = new Grand();
            return *_instance;
        }
        const SurfEtat& Grand::age()const{
            return Moyen::getInstance();
        }
    }
}
