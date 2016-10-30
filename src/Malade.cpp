#include "include/froppie/fropEtat/Malade.hpp"
#include "include/froppie/fropEtat/Sain.hpp"
#include "include/froppie/fropEtat/Mort.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            
            const Malade Malade::_malade;
        
            Malade::Malade(){

            }

            void Malade::setMort(Froppie& cancered)const{
                cancered.setEtat(Mort::getMort());
            }

            void Malade::setSain(Froppie& cancered)const{
                cancered.setEtat(Sain::getSain());
            }

            void Malade::setMalade(Froppie& cancered)const{
                setMort(cancered);
            }

            const Malade& Malade::getMalade()const{
                return _malade;
            }

            const string& Malade::nomEtat()const{
                return "Malade";
            }
        }

        
    }
}