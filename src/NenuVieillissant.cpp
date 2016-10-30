#include "include/nenuphar/strategy/SurfCanDie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            void NenuVieillissant::vieillir(Surface& victim)const{
                victim.age();
            }
        }
    }
}
