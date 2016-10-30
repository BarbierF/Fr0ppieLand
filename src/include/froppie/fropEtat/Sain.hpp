#ifndef SAIN_HPP
#define SAIN_HPP

#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            class Sain: public FropEtat{

            public:
                void setMort(Froppie& cancered)const;
                void setSain(Froppie& cancered)const;
                void setMalade(Froppie& cancered)const;

                const std::string& nomEtat()const override;

                static const Sain& getSain() const;

            private:
                Sain();

                static const Sain _sain;
            };
        }

        
    }
}

#endif