#ifndef MORT_HPP
#define MORT_HPP

#include "FropEtat.hpp"

namespace froppieLand{

    namespace modele{

        class Mort: public FropEtat{

        public:
            void setMort(Froppie& cancered)const;
            void setSain(Froppie& cancered)const;
            void setMalade(Froppie& cancered)const;

            static const Mort& getMort();
        
        private:
            Mort();

            static const Mort _mort;
        };
    }
}

#endif