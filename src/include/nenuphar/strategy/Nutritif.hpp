#ifndef NUTRITIF_HPP
#define NUTRITIF_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Nutritif: public SurfCanDie{
            friend class FactoryStrategyNenuphar;
            public:
                void souffrir(Froppie& victim)const;
                const std::string nomStrategy()const override;
            private:
                Nutritif()=default;
            };
        }
        
    }
}

#endif // NUTRITIF_HPP
