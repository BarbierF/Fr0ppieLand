#ifndef MALADE_HPP
#define MALADE_HPP

#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            /**
             * Etat Malade de Froppie,
             * Implémenté en Singleton
             */
            class Malade: public FropEtat{

            public:

                Malade(const Malade&) = delete;

                Malade& operator=(const Malade& ) = delete;

            public: 
                void setMort(Froppie& froppie)const;
                void setSain(Froppie& froppie)const;
                void setMalade(Froppie& froppie)const;

                const std::string nomEtat()const override;

                
                /**
                * Fonction de récupération/instanciation de l'instance de Malade
                * @return L'instance de Malade
                */
                static const Malade& getMalade();

            private:
                /**
                 * Constructeur privé du singleton
                 */
                Malade();
                
                /**
                 * Composante statique du singleton
                 */
                static const Malade _malade; 
            };
        }

        
    }
}

#endif