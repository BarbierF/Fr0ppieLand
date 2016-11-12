#ifndef INEXISTANT_HPP
#define INEXISTANT_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             * Taille de nénuphar Inexistant (mort)
             * Implémentée en Singleton
             */
            class Inexistant:public SurfEtat{
            public:
                void age(Surface& victim)const override;
                const std::string nomEtat()const override;

                static SurfEtat const* getInstance();
            private:
                /**
                 * Définition du constructeur par défaut privé
                 */
                Inexistant()=default;
            private:
                /**
                 * Composante statique du singleton
                 */
                static const Inexistant _inexistant;
            };
        }
        
    }
}

#endif /* INEXISTANT_HPP */
