#include "include/Malade.hpp"
#include "include/Sain.hpp"
#include "include/Mort.hpp"

namespace froppieLand{

    namespace modele{

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

        const Malade& Malade::getMalade(){
            return _malade;
        }
    }
}