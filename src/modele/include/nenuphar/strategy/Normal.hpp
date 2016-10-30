#ifndef NORMAL_HPP
#define NORMAL_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Normal: public NenuVieillissant{
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Normal()=default;
            };
        }
        
    }
}

#endif // NORMAL_HPP
