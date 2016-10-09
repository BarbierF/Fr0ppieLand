#include "include/Sain.hpp"
#include "include/Malade.hpp"
#include "include/Mort.hpp"

namespace froppieLand{

    namespace modele{

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

        const Sain& Sain::getSain(){
            return _sain;
        }
    }
}