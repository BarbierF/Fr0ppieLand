#ifndef SAIN_HPP
#define SAIN_HPP

#include "FropEtat.hpp"

namespace froppieLand{

    namespace modele{

        class Sain: public FropEtat{

        public:
            void setMort(Froppie& cancered)const;
            void setSain(Froppie& cancered)const;
            void setMalade(Froppie& cancered)const;

            static const Sain& getSain();

        private:
            Sain();

            static const Sain _sain;
        };
    }
}

#endif