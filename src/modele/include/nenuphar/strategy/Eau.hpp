#ifndef EAU_HPP
#define EAU_HPP

#include "NenuNonVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant la surface d'eau
             */
            class Eau: public NenuNonVieillissant{
                /**
                 * Classe amie pour construction dans la factory
                 */
                friend class FactoryStrategyNenuphar;
            public:
                void souffrir(froppie::Froppie& victim)const override;
                const std::string nomStrategy()const override;
            private:
                /**
                 * Masquage du constructeur par défaut pour l'instanciation uniquement dans la factory
                 */
                Eau()=default;
            };
        }
        
    }
}


#endif /* EAU_HPP */
