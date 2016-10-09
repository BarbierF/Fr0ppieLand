#ifndef MORTEL_HPP
#define MORTEL_HPP 1

#include "SurfCanDie.hpp"

namespace froppieLand{
    namespace modele{
        class Mortel: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        private:
            Mortel()=default;
        };
    }
}

#endif // MORTEL_HPP
