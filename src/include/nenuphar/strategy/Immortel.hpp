#ifndef IMMORTEL_HPP
#define IMMORTEL_HPP 

#include "NenuNonVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Immortel: SurfCannotDie{
            friend class FactoryStrategyNenuphar;
            public:
                void souffrir(Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Immortel()=default;
            };
        }
        
    }
}

#endif // IMMORTEL_HPP
