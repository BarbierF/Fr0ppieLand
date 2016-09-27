#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        class StrategyNenuphar{
        public:
            virtual const bool& can_die()const =0;
            virtual const int& affectHealth(const int& pv)const =0;
            //virtual const bool& can_kill()const =0;
            virtual const FropEtat& affectFropEtat()const=0;
        };
    }
}

#endif /* STRATEGYNENUPHAR_HPP */
