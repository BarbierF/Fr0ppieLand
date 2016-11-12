#ifndef SAIN_HPP
#define SAIN_HPP

#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            /**
             * Etat Sain de Froppie,
             * Implémenté en Singleton
             */
            class Sain: public FropEtat{

            public:
                void setMort(Froppie& cancered)const;
                void setSain(Froppie& cancered)const;
                void setMalade(Froppie& cancered)const;

                const std::string nomEtat()const override;

                /**
                * Fonction de récupération/instanciation de l'instance de Sain
                * @return L'instance de Sain
                */
                static const Sain& getSain();

            private:
                /**
                 * Constructeur privé du singleton
                 */
                Sain();
                
                /**
                 * Composante statique du singleton
                 */
                static const Sain _sain;
            };
        }

        
    }
}

#endif