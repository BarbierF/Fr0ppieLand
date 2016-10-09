#ifndef SURFCANDIE_HPP
#define SURFCANDIE_HPP 1

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        class SurfCanDie: public StrategyNenuphar{
        public:
            const bool& canDie()const;
        };
    }
}

#endif // SURFCANDIE_HPP
