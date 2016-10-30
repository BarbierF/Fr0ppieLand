#ifndef MORT_HPP
#define MORT_HPP

#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            class Mort: public FropEtat{

            public:
                void setMort(Froppie& cancered)const;
                void setSain(Froppie& cancered)const;
                void setMalade(Froppie& cancered)const;

                const std::string& nomEtat()const override; 

                static const Mort& getMort()const;
            
            private:
                Mort();

                static const Mort _mort;
            };
        }

        
    }
}

#endif