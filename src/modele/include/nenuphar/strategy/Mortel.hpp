#ifndef MORTEL_HPP
#define MORTEL_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant un nénuphar mortel
             */
            class Mortel: public NenuVieillissant{
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
                Mortel()=default;
            };
        }
        
    }
}

#endif // MORTEL_HPP
