#ifndef Malade_hpp
#define Malade_hpp

#include "FropEtat.hpp"

/**
 * @class Malade Malade.hpp
 *
 * Déclaration de la classe Malade représentant la grenouille a l etat malade et ses effets.
 */

using namespace froppieLand;

    class Malade: public FropEtat {
        
        public:
       /**
        * Recupere le nom de l etat.
        */
        std::string getEtat() const override;

        /**
        * Recupere l effet de l etat malade.
        */
        void getEffet() const override;
       
    };


#endif
