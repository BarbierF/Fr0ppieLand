#ifndef MORTEL_HPP
#define MORTEL_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Mortel: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
            public:
                void souffrir(Froppie& victim)const;
                const std::string nomStrategy()const override;
            private:
                Mortel()=default;
            };
        }
        
    }
}

#endif // MORTEL_HPP
