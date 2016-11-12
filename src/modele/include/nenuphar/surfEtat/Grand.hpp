#ifndef GRAND_HPP
#define GRAND_HPP


#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            /**
             * Taille de nénuphar grande
             * Implémentée en Singleton
             */
            class Grand:public SurfEtat{
            public:
                static SurfEtat const* getInstance();
                void age(Surface& victim)const override;

                const std::string nomEtat()const override;
            private:
                /**
                 * Définition du constructeur par défaut privé
                 */
                Grand()=default;
            public:
            private:
                /**
                 * Composante statique du singleton
                 */
                static const Grand _grand;
            };
        }
        
    }
}

#endif /* GRAND_HPP */
