#include "include/Moyen.hpp"
#include "include/Petit.hpp"

namespace froppieLand{
    namespace modele{
        SurfEtat& Moyen::getInstance(){
            if(Moyen::_instance)
                Moyen::_instance = new Moyen();
            return *Moyen::_instance;
        }
        const SurfEtat& Moyen::age()const{
            return Petit::getInstance();
        }
    }
}
