#ifndef SURFCANDIE_HPP
#define SURFCANDIE_HPP 

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             * Classe définissant un nénuphar ou surface pouvant vieillir
             */
            class NenuVieillissant: public StrategyNenuphar{
            public:
                virtual void souffrir(froppie::Froppie& victim)const = 0;
                void vieillir(Surface& victim)const override;
                virtual const std::string nomStrategy()const = 0;
            };
        }
        
    }
}

#endif // SURFCANDIE_HPP
