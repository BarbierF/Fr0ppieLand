#ifndef NORD_HPP
#define NORD_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        /**
         * Direction Nord,
         * Implémentée en Singleton.
         */
        class Nord: public Direction{

        public:
            /**
             * Fonction de récupération/instanciation de l'instance de Nord
             * @return L'instance de Nord
             */
            static const Nord& getNord();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            /**
             *  Suppression du constructeur par copie
             */
            Nord(const Nord& ) = delete;

            /**
             *  Suppression de l'opérateur d'attribution
             */
            Nord& operator=(const Nord& ) = delete;

        private:
            /**
             * Constructeur privé du singleton
             */
            Nord();

            /**
             * Composante statique du singleton
             */
            static const Nord _nord;
        };
    }
}

#endif