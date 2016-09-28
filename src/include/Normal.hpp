#ifndef NORMAL_HPP
#define NORMAL_HPP 1

#include "SurfCanDie.hpp"

namespace froppieLand{
    namespace modele{
        class Normal: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        private:
            Normal()=default;
        };
    }
}

#endif // NORMAL_HPP
