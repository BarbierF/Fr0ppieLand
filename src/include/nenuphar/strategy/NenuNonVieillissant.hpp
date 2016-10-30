#ifndef SURFCANNOTDIE_HPP
#define SURFCANNOTDIE_HPP 

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class NenuNonViellissant: public StrategyNenuphar{
            public:
                virtual void souffrir(Froppie& victim)const = 0;
                void vieillir(Surface& victim)const override;
                virtual const std::string& nomStrategy()const override;
            };
        }
        
    }
}

#endif // SURFCANNOTDIE_HPP
