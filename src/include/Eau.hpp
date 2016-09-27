#ifndef EAU_HPP
#define EAU_HPP

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        class Eau: public StrategyNenuphar{
            friend class FactoryStrategyNenuphar;
        public:
            const StrategyNenuphar& get_instance();
            const bool& canDie()const;
            //const int& affect_health()const;
            //const bool& canKill()const =0;
            void souffrir(Froppie& victim)const;
        };
    }
}


#endif /* EAU_HPP */
