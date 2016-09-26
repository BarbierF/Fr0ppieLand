#ifndef Sain_hpp
#define Sain_hpp

#include "FropEtat.hpp"

/**
 * @class Sain Sain.hpp
 *
 * Déclaration de la classe Sain représentant la grenouille a l etat sain et ses effets.
 */

using namespace froppieLand;

    class Sain: public FropEtat {

        public:
        /**
        * Recupere le nom de l etat.
        */
        std::string getEtat() const override;

        /**
        * Recupere l effet de l etat sain.
        */
        void getEffet() const override;
       
    };


#endif
