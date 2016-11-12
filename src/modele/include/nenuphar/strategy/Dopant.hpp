#ifndef DOPANT_HPP
#define DOPANT_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant le type Dopant d'un nénuphar
             */
            class Dopant: public NenuVieillissant{
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:                
                Dopant()=default;
            };
        }
        
    }
}

#endif // DOPANT_HPP
