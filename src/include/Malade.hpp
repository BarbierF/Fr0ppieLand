#ifndef MALADE_HPP
#define MALADE_HPP

#include "FropEtat.hpp"

namespace froppieLand{

    namespace modele{

        class Malade: public FropEtat{

        public: 
            void setMort(Froppie& froppie)const;
            void setSain(Froppie& froppie)const;
            void setMalade(Froppie& froppie)const;

            static const Malade& getMalade();

        private:
            Malade();

            static const Malade _malade; 
        };
    }
}

#endif