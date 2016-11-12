#ifndef SUD_HPP
#define SUD_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{
        
        /**
         * Direction Sud,
         * Implémentée en Singleton.
         */
        class Sud: public Direction{

        public:
            /**
             * Fonction de récupération/instanciation de l'instance de Est
             * @return L'instance de Est
             */
            static const Sud& getSud();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            /**
             *  Suppression du constructeur par copie
             */
            Sud(const Sud& ) = delete;

            /**
             *  Suppression de l'opérateur d'attribution
             */
            Sud& operator=(const Sud& ) = delete;

        private:
            /**
             * Constructeur privé du singleton
             */
            Sud();

            /**
             * Composante statique du singleton
             */
            static const Sud _sud;
        };
    }
}
#endif