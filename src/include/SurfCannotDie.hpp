#ifndef SURFCANNOTDIE_HPP
#define SURFCANNOTDIE_HPP 1

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        class SurfCannotDie: public StrategyNenuphar{
        public:
            const bool& canDie()const;
        };
    }
}

#endif // SURFCANNOTDIE_HPP
