#include "include/froppie/fropEtat/Mort.hpp"
#include "include/froppie/fropEtat/Malade.hpp"
#include "include/froppie/fropEtat/Sain.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            const Mort Mort::_mort;

            Mort::Mort(){

            }

            void Mort::setMort(Froppie& cancered)const{

            }

            void Mort::setSain(Froppie& cancered)const{

            }

            void Mort::setMalade(Froppie& cancered)const{

            }

            Mort const* Mort::getMort(){
                return &_mort;
            }

            const std::string Mort::nomEtat()const{
                return "Mort";
            }
        }
    }
}