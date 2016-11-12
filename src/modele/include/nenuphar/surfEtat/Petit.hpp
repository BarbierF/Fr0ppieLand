#ifndef PETIT_HPP
#define PETIT_HPP
#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             * Taille de nénuphar petite
             * Implémentée en Singleton
             */
            class Petit:public SurfEtat{
            public:
                static SurfEtat const* getInstance();
                void age(Surface& victim)const override;

                const std::string nomEtat()const;
            private:
                /**
                 * Définition du constructeur par défaut privé
                 */
                Petit()=default;
            public:
            private:
                /**
                 * Composante statique du singleton
                 */
                static const Petit _petit;
            };
        }
        
    }
}

#endif /* PETIT_HPP */
