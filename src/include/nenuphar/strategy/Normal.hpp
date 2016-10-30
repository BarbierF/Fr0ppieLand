#ifndef NORMAL_HPP
#define NORMAL_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Normal: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
            public:
                void souffrir(Froppie& victim)const;
                const std::string nomStrategy()const override;
            private:
                Normal()=default;
            };
        }
        
    }
}

#endif // NORMAL_HPP
