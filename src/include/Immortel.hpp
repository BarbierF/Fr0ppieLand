#ifndef IMMORTEL_HPP
#define IMMORTEL_HPP 1

#include "SurfCannotDie.hpp"

namespace froppieLand{
    namespace modele{
        class Immortel: SurfCannotDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        private:
            Immortel()=default;
        };
    }
}

#endif // IMMORTEL_HPP
