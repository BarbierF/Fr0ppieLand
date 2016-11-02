#include "BarreChrono.hpp"
#include "FroppieVue.hpp"

namespace froppieLand{
    namespace vue{

        const unsigned int BarreChrono::_tempsChrono = 60;
        const unsigned int BarreChrono::_tempsVieillissement = 1;

        BarreChrono::BarreChrono(FroppieVue& vue, Glib::ustring)
            :Gtk::Frame(titre), _vue(&vue), _enCours(false){
            
            const Presentateur& presentateur = _vue->getPresentateur();


            _barProgression.set_fraction(0);

            Glig::ustring libelle(0 + "secondes");
            _barProgression.set_text()

        } 

        void BarreChrono::progression(){

            double pas = _tempsVieillissement / _tempsChrono;
            double valSuivante = _barProgression.get_fraction() + pas;

            //On veut éviter les erreurs donc si on dépasse on remet à zéro
            if(valCourante >= 1.0) valCourante = 0; 

            _barProgression.set_fraction(pas);
            
            _barProgression.set_text(Glib::ustring(pas) + " secondes");
        }

        void BarreChrono::lancerChrono(){

            if(!_enCours){
                _barChronoThread(Glib::Thread::create(
                    sigc::men_fun($this, &BarreChrono::traitementChronoThread)
                ));
                enCours = true;            
            }
        }

        void BarreChrono::stopperChrono(){

            if(!_enCours) return;
            _barProgression.set_fraction(0);
            _barChronoThread.join();        //on attend la fin du thread pour pouvoir le terminer comme il se doit
        }

        void BarreChrono::traitementChronoThread(){

            for(unsigned int i = 0 ; i <= _tempsChrono ; i += _tempsVieillisement){
                progression();
                _vue->leTempsPasse();
                Glib::sleep(1); //ou Glib::usleep(1000);
                
            }

        }

    }
}