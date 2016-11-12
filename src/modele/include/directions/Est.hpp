#ifndef EST_HPP
#define EST_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        /**
         * Direction Est,
         * Implémentée en Singleton.
         */
        class Est: public Direction{

        public:
            /**
             * Fonction de récupération/instanciation de l'instance de Est
             * @return L'instance de Est
             */
            static const Est& getEst();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            /**
             *  Suppression du constructeur par copie
             */
            Est(const Est& ) = delete;

            /**
             *  Suppression de l'opérateur d'attribution
             */
            Est& operator=(const Est& ) = delete;

        private:
            /**
             * Constructeur privé du singleton
             */
            Est();
            
            /**
             * Composante statique du singleton
             */
            static const Est _est;
        };
    }
}
#endif