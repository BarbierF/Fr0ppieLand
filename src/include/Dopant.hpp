#ifndef DOPANT_HPP
#define DOPANT_HPP 1

#include "SurfCanDie.hpp"

namespace froppieLand{
    namespace modele{
        class Dopant: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        private:
            Dopant()=default;
        };
    }
}

#endif // DOPANT_HPP
