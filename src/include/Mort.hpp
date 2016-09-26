#ifndef Mort_hpp
#define Mort_hpp

#include "FropEtat.hpp"


/**
 * @class Mort Mort.hpp
 *
 * Déclaration de la classe Mort représentant la grenouille a l etat mort et ses effets.
 */

using namespace froppieLand;

    class Mort: public FropEtat {

        public:
        /**
        * Recupere le nom de l etat.
        */
        std::string getEtat() const override;

        /**
        * Recupere l effet de l etat mort.
        */
        void getEffet() const override;
       
    };


#endif
