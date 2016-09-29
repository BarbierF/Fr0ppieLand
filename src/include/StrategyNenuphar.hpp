#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

#include "Froppie.hpp"

namespace froppieLand{
    namespace modele{
        class StrategyNenuphar{
        public:
            virtual const bool& canDie()const =0;
            virtual void souffrir(Froppie& victim)const=0;
        };
    }
}

#endif /* STRATEGYNENUPHAR_HPP */
