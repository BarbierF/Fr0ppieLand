#ifndef VENENEUX_HPP
#define VENENEUX_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Veneneux: public NenuVieillissant{                
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Veneneux()=default;

            };
        }
        
    }
}

#endif // VENENEUX_HPP
