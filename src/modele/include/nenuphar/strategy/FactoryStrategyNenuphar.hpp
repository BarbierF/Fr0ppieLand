#ifndef FACTORYSTRATEGYNENUPHAR_HPP
#define FACTORYSTRATEGYNENUPHAR_HPP 

#include "Eau.hpp"
#include "Immortel.hpp"
#include "Veneneux.hpp"
#include "Normal.hpp"
#include "Nutritif.hpp"
#include "Dopant.hpp"
#include "Mortel.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             * Factory contenant les différentes références vers les stratégies des différents nénuphars
             */
            class FactoryStrategyNenuphar{
            public:
                /**
                 * Enumération des différents types de nénuphars pour la construction
                 */
                enum TypeNenu{
                    eau,
                    immortel,
                    veneneux,
                    normal,
                    nutritif,
                    dopant,
                    mortel
                };

            public:
                /**
                 * Méthode de construction des Stratégies
                 */
                static StrategyNenuphar const* getStrategy(TypeNenu type);
            private:
                //===== Références statiques vers les différentes stratégies =====
                static const Eau _eau;
                static const Immortel _immortel;
                static const Veneneux _veneneux;
                static const Normal _normal;
                static const Nutritif _nutritif;
                static const Dopant _dopant;
                static const Mortel _mortel;
            };
        }
        
    }
}

#endif // FACTORYSTRATEGYNENUPHAR_HPP
