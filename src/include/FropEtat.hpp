#ifndef FROP_ETAT_HPP
#define FROP_ETAT_HPP

#include "Froppie.hpp"

namespace froppieLand{

    namespace modele{

        class FropEtat{

        public:
            virtual void setMort(Froppie& cancered)const = 0;
            virtual void setSain(Froppie& cancered)const = 0;
            virtual void setMalade(Froppie& cancered)const= 0;

        };
    }
}

#endif