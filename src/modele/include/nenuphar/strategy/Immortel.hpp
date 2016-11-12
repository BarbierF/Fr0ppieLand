#ifndef IMMORTEL_HPP
#define IMMORTEL_HPP 

#include "NenuNonVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant un nénuphar immortel
             */
            class Immortel: NenuNonVieillissant{
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Immortel()=default;
            };
        }
        
    }
}

#endif // IMMORTEL_HPP
