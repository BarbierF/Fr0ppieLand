#ifndef EAU_HPP
#define EAU_HPP

#include "SurfCannotDie.hpp"

namespace froppieLand{
    namespace modele{
        class Eau: public SurfCannotDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        public:
            Eau()=default;
        };
    }
}


#endif /* EAU_HPP */
