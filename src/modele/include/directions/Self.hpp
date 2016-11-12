#ifndef SELF_DIR_HPP
#define SELF_DIR_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        /**
         * Direction Self,
         * Correspond à rester sur la même position
         * Implémentée en Singleton.
         */
        class Self: public Direction{

        public:
            /**
             * Fonction de récupération/instanciation de l'instance de Self
             * @return L'instance de Self
             */
            static const Self& getSelf();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            /**
             *  Suppression du constructeur par copie
             */
            Self(const Self& ) = delete;

            /**
             *  Suppression de l'opérateur d'attribution
             */
            Self& operator=(const Self& ) = delete;

        private:
            /**
             * Constructeur privé du singleton
             */
            Self();
            
            /**
             * Composante statique du singleton
             */
            static const Self _self;
        };
    }
}

#endif