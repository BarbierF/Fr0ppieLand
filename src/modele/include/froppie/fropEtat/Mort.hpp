#ifndef MORT_HPP
#define MORT_HPP

#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            /**
             * Etat Mort de Froppie,
             * Implémenté en Singleton
             */
            class Mort: public FropEtat{

            public:
                void setMort(Froppie& cancered)const;
                void setSain(Froppie& cancered)const;
                void setMalade(Froppie& cancered)const;

                const std::string nomEtat()const override; 

                /**
                * Fonction de récupération/instanciation de l'instance de Mort
                * @return L'instance de Mort
                */
                static const Mort& getMort();
            
            private:
                /**
                 * Constructeur privé du singleton
                 */
                Mort();

                /**
                 * Composante statique du singleton
                 */
                static const Mort _mort;
            };
        }

        
    }
}

#endif