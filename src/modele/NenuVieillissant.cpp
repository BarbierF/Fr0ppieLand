#include "NenuVieillissant.hpp"
#include "Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            
            void NenuVieillissant::vieillir(Surface& victim)const{
                victim.vieillirEtat();
            }
        }
    }
}
