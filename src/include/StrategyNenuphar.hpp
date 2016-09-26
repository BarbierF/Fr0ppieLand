#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

#include "dummy/DummyFropEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Froppie;
        class StrategyNenuphar{
        public:
            virtual const StrategyNenuphar& get_instance()=0;
            virtual const bool& can_die()const =0;
            virtual const int& affect_health()const =0;
            virtual const bool& can_kill()const =0;
            virtual DummyFropEtat& affectFroppie(int& pv)const=0;
        protected:
            static StrategyNenuphar* _instance;
        };
    }
}

#endif /* STRATEGYNENUPHAR_HPP */
