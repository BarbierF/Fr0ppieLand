#ifndef EAU_HPP
#define EAU_HPP

#include "NenuNonVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Eau: public SurfCannotDie{
            friend class FactoryStrategyNenuphar;
            public:
                void souffrir(Froppie& victim)const override;
                const std::string& nomStrategy()const override;
            public:
                Eau()=default;
            };
        }
        
    }
}


#endif /* EAU_HPP */
