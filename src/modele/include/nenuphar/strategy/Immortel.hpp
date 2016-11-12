#ifndef IMMORTEL_HPP
#define IMMORTEL_HPP 

#include "NenuNonVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant un nénuphar immortel
             */
            class Immortel: NenuNonVieillissant{
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
                Immortel()=default;
            };
        }
        
    }
}

#endif // IMMORTEL_HPP
