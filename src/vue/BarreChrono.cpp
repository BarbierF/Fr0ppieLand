#include "BarreChrono.hpp"
#include "FroppieVue.hpp"

namespace froppieLand{
    namespace vue{

        BarreChrono::BarreChrono(FroppieVue& vue, Glib::ustring titre
            , const unsigned int& tempsChrono, const unsigned int& tempsViellissement)
            :Gtk::Frame(titre), _vue(vue), _enCours(false)
            , _tempsChrono(tempsChrono)
            , _tempsVieillissement(tempsViellissement){
            
            _barProgression.set_fraction(0);

            Glib::ustring libelle(0 + "secondes");
            _barProgression.set_text(libelle);

        } 

        void BarreChrono::progression(){

            double pas = _tempsVieillissement / _tempsChrono;
            double valSuivante = _barProgression.get_fraction() + pas;

            //On veut éviter les erreurs donc si on dépasse on remet à zéro
            if(valSuivante >= 1.0) valSuivante = 0; 

            _barProgression.set_fraction(pas);
            
            _barProgression.set_text(Glib::ustring(std::to_string(pas)) + " secondes");
        }

        void BarreChrono::startChrono(){

            if(!_enCours){

                _chronoThread = new (&BarreChrono::traitementChronoThread);
                _enCours = true;            
            }
        }

        void BarreChrono::stopChrono(){

            if(!_enCours) return;
            _barProgression.set_fraction(0);
            _chronoThread.join();
            _enCours = false;        //on attend la fin du thread pour pouvoir le terminer comme il se doit
        }
        //ne fonctionnera pas
        void BarreChrono::traitementChronoThread(){

            for(unsigned int i = 0 ; i <= _tempsChrono ; i += _tempsVieillissement){
                progression();
                _vue.leTempsPasse();
                Glib::Threads::usleep(1000); 
                
            }

            timesUp();

        }

        void BarreChrono::timesUp(){
            _enCours = false;
            _vue.finPartie();
        }

    }
}