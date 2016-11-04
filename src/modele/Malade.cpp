#include "Malade.hpp"
#include "Sain.hpp"
#include "Mort.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            
            const Malade Malade::_malade;
        
            Malade::Malade(){

            }

            void Malade::setMort(Froppie& cancered)const{
                cancered.setMort();
            }

            void Malade::setSain(Froppie& cancered)const{
                cancered.setSain();
            }

            void Malade::setMalade(Froppie& cancered)const{
                cancered.setMort();
            }

            const Malade& Malade::getMalade(){
                return _malade;
            }

            const std::string Malade::nomEtat()const{
                return "Malade";
            }
        }

        
    }
}