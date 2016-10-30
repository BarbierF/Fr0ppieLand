#include "include/froppie/fropEtat/Sain.hpp"
#include "include/froppie/fropEtat/Malade.hpp"
#include "include/froppie/fropEtat/Mort.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            const Sain Sain::_sain;

        Sain::Sain(){

        }

        void Sain::setMort(Froppie& cancered)const{
            cancered.setEtat(Mort::getMort());
        }
        void Sain::setSain(Froppie& cancered)const{
            
        }
        void Sain::setMalade(Froppie& cancered)const{
            cancered.setEtat(Malade::getMalade());
        }

        const Sain& Sain::getSain() const{
            return _sain;
        }

        const string& Sain::nomEtat()const{
            return "Sain";
        }
    }
    }
}