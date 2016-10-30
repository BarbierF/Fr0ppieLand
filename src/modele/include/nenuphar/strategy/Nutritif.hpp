#ifndef NUTRITIF_HPP
#define NUTRITIF_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Nutritif: public NenuVieillissant{
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Nutritif()=default;
            };
        }
        
    }
}

#endif // NUTRITIF_HPP
