#ifndef DOPANT_HPP
#define DOPANT_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Dopant: public NenuVieillissant
            friend class FactoryStrategyNenuphar;
            public:
                void souffrir(Froppie& victim)const override;
                const std::string& nomStrategy()const override;
            private:
                Dopant()=default;
            };
        }
        
    }
}

#endif // DOPANT_HPP
