#ifndef MOYEN_HPP
#define MOYEN_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             * Taille de nénuphar moyenne
             * Implémentée en Singleton
             */
            class Moyen:public SurfEtat{
            public:
                /**
                 * Méthode de récupération/instanciation de l'instance du Singleton
                 * @return l'instance du singleton
                 */
                static SurfEtat const* getInstance();
                void age(Surface& victim)const override;

                const std::string nomEtat()const override;
            private:
                /**
                 * Définition du constructeur par défaut privé
                 */
                Moyen()=default;
            public:
            private:
                /**
                 * Composante statique du singleton
                 */
                static const Moyen _moyen;
            };
        }
        
    }
}

#endif /* MOYEN_HPP */
