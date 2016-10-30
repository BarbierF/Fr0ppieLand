#ifndef SURFCANDIE_HPP
#define SURFCANDIE_HPP 

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class NenuVieillissant: public StrategyNenuphar{
            public:
                virtual void souffir(Froppie& victim)const = 0;
                void vieillir(Surface& victim)const override;
                virtual const std::string& nomStrategy()const override;
            };
        }
        
    }
}

#endif // SURFCANDIE_HPP
