#include "include/nenuphar/surfEtat/Grand.hpp"
#include "include/nenuphar/surfEtat/Moyen.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            SurfEtat& Grand::getInstance(){
                if(!Grand::_instance)
                    Grand::_instance = new Grand();
                return *_instance;
            }

            const SurfEtat& Grand::age()const{
                return Moyen::getInstance();
            }

            const std::string& nomEtat()const{
                return "Grand";
            }
        }
        
    }
}
