#include "include/nenuphar/surfEtat/Moyen.hpp"
#include "include/nenuphar/surfEtat/Petit.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            SurfEtat& Moyen::getInstance(){
                if(Moyen::_instance)
                    Moyen::_instance = new Moyen();
                return *Moyen::_instance;
            }
            const SurfEtat& Moyen::age()const{
                return Petit::getInstance();
            }

            const std::string& nomEtat()const{
                return "Moyen";
            }
        }
        }
        
}
