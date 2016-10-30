#ifndef SURFCANNOTDIE_HPP
#define SURFCANNOTDIE_HPP 

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class NenuNonVieillissant: public StrategyNenuphar{
            public:
                virtual void souffrir(froppie::Froppie& victim)const = 0;
                void vieillir(Surface& victim)const override;
                virtual const std::string nomStrategy()const = 0;
            };
        }
        
    }
}

#endif // SURFCANNOTDIE_HPP
