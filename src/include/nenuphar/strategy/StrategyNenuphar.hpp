#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

#include <string>

#include "../../froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        class StrategyNenuphar{
        public:
            virtual const bool& canDie()const =0;
            virtual void souffrir(Froppie& victim)const=0;
            virtual const std::string& nomStrategy()const;
        };
    }
}

#endif /* STRATEGYNENUPHAR_HPP */
