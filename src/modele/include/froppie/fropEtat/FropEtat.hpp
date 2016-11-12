#ifndef FROP_ETAT_HPP
#define FROP_ETAT_HPP

#include <string>

#include "Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            /**
             *  Classe Abstraite définissant les états possibles de Froppie
             */
            class FropEtat{

            public:
                
                /**
                 * Action de mort sur Froppie
                 * @param cancered Froppie cible
                 */
                virtual void setMort(Froppie& cancered)const = 0;
                
                /**
                 * Action de soin sur Froppie
                 * @param cancered Froppie cible
                 * 
                 */
                virtual void setSain(Froppie& cancered)const = 0;
                
                /**
                 * Action de contamination de Froppie
                 * @param cancered Froppie cible
                 */
                virtual void setMalade(Froppie& cancered)const= 0;

                /**
                 * Nom d'affichage de l'état
                 * @return Le nom de Froppie
                 */
                virtual const std::string nomEtat()const = 0;

            };
        }
    }
}

#endif