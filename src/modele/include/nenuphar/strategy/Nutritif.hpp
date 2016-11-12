#ifndef NUTRITIF_HPP
#define NUTRITIF_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant un nénuphar nutritif
             */
            class Nutritif: public NenuVieillissant{
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
                Nutritif()=default;
            };
        }
        
    }
}

#endif // NUTRITIF_HPP
