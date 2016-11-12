#ifndef VENENEUX_HPP
#define VENENEUX_HPP 

#include "NenuVieillissant.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             *  Classe décrivant le caractère Vénéneux d'un nénuphar
             */
            class Veneneux: public NenuVieillissant{
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
                Veneneux()=default;

            };
        }
        
    }
}

#endif // VENENEUX_HPP
