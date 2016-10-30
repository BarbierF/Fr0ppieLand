#include "include/nenuphar/strategy/NenuVieillissant.hpp"
#include "include/nenuphar/Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            
            void NenuVieillissant::vieillir(Surface& victim)const{
                victim.vieillirEtat();
            }
        }
    }
}
