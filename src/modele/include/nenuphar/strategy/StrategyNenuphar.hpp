#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

#include <string>

#include "../../froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Surface;
            class StrategyNenuphar{
            public:
                
                virtual void souffrir(froppie::Froppie& victim)const = 0;
                virtual void vieillir(Surface& victim)const = 0;
                virtual const std::string nomStrategy()const = 0;
            };
        }
        
    }
}

#endif /* STRATEGYNENUPHAR_HPP */
