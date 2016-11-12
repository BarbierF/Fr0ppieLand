#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

#include <string>


namespace froppieLand{
    namespace modele{
        namespace froppie{

            class Froppie;
        }

        namespace nenuphar{

            class Surface;
            /**
             * Définition supérieure des types de surface
             */
            class StrategyNenuphar{
            public:
                /**
                 * Méthode de stratégie pour modifier les points de vie de Froppie
                 */
                virtual void souffrir(froppie::Froppie& victim)const = 0;
                /**
                 * Méthode de vieillissement des nénuphars
                 */
                virtual void vieillir(Surface& victim)const = 0;
                /**
                 * Nom de la stratégie définissant le type de la surface
                 * @return le nom du type
                 */
                virtual const std::string nomStrategy()const = 0;
            };
        }
        
    }
}

#endif /* STRATEGYNENUPHAR_HPP */
