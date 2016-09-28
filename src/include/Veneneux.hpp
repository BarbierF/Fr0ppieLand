#ifndef VENENEUX_HPP
#define VENENEUX_HPP 1

#include "SurfCanDie.hpp"

namespace froppieLand{
    namespace modele{
        class Veneneux: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        private:
            Veneneux()=default;

        };
    }
}

#endif // VENENEUX_HPP
