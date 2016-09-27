#ifndef IMMORTEL_HPP
#define IMMORTEL_HPP 1

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        class Immortel: StrategyNenuphar{
            friend class FactoryStrategyNenuphar;
        public:
            const bool& canDie()const;
            //virtual const int& affectHealth(const int& pv)const;
            //virtual const FropEtat& affectFropEtat()const;
            void souffrir(Froppie& victim)const;
        private:
            Immortel()=default;
        };
    }
}

#endif // IMMORTEL_HPP
