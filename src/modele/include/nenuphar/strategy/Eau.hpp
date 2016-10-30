#ifndef EAU_HPP
#define EAU_HPP

#include "NenuNonVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Eau: public NenuNonVieillissant{
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                Eau()=default;
            };
        }
        
    }
}


#endif /* EAU_HPP */
