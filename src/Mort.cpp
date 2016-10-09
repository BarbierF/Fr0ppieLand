#include "include/Mort.hpp"
#include "include/Malade.hpp"
#include "include/Sain.hpp"

namespace froppieLand{

    namespace modele{

        const Mort Mort::_mort;

        Mort::Mort(){

        }

        void Mort::setMort(Froppie& cancered)const{

        }
        void Mort::setSain(Froppie& cancered)const{

        }
        void Mort::setMalade(Froppie& cancered)const{

        }

        const Mort& Mort::getMort(){
            return _mort;
        }
    }
}