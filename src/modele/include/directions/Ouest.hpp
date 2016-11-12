#ifndef OUEST_HPP
#define OUEST_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        /**
         * Direction Ouest,
         * Implémentée en Singleton.
         */
        class Ouest: public Direction{

        public:
            /**
             * Fonction de récupération/instanciation de l'instance de Ouest
             * @return L'instance de Ouest
             */
            static const Ouest& getOuest();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            /**
             *  Suppression du constructeur par copie
             */
            Ouest(const Ouest& ) = delete;
            
            /**
             *  Suppression de l'opérateur d'attribution
             */
            Ouest& operator=(const Ouest& ) = delete;

        private:
            /**
             * Constructeur privé du singleton
             */
            Ouest();
            
            /**
             * Composante statique du singleton
             */
            static const Ouest _ouest;
        };
    }
}

#endif