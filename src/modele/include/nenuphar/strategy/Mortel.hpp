#ifndef MORTEL_HPP
#define MORTEL_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Mortel: public NenuVieillissant{
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Mortel()=default;
            };
        }
        
    }
}

#endif // MORTEL_HPP
