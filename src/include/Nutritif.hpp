#ifndef NUTRITIF_HPP
#define NUTRITIF_HPP 1

#include "SurfCanDie.hpp"

namespace froppieLand{
    namespace modele{
        class Nutritif: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
        public:
            void souffrir(Froppie& victim)const;
        private:
            Nutritif()=default;
        };
    }
}

#endif // NUTRITIF_HPP
