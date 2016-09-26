#ifndef FropEtat_hpp
#define FropEtat_hpp

#include <string>

/**
 * @class FropEtat FropEtat.hpp
 *
 * Déclaration de la classe abstraite FropEtat représentant un 
 * etat de la grenouille.
 */

namespace froppieLand
{
   class FropEtat {

       protected:
       /**
        * Nom de l etat courrant de la grenouille.
        */
        std::string nom_;

        /**
        * Etat courant de la grenouille.
        */
       int effet_;
 

       public:

       /**
        * Retourne le nom de l etat.
        *
        * @return le nom de l etat.
        */
        virtual std::string getEtat() const = 0;

         /**
        * Retourne l effet de l etat.
        *
        * @return l effet de l etat.
        */
        virtual void getEffet() const = 0;

    };    
}

#endif
