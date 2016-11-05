#include <chrono>

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

                _chronoThread.reset(new std::thread(&BarreChrono::traitementChronoThread));
                _enCours = true;            
            }
        }

        void BarreChrono::resetChrono(){
            if(!_enCours) return;
            _barProgression.set_fraction(0);
            _threadProgression = 0;
        }

        void BarreChrono::stopChrono(){

            if(!_enCours) return;
            _barProgression.set_fraction(0);
            _enCours = false;        
        }
        //ne fonctionnera pas
        void BarreChrono::traitementChronoThread(){

            while(_threadProgression < _tempsChrono){
                progression();
                _vue.leTempsPasse();
                std::this_thread::sleep_for(std::chrono::seconds(1));

                _threadProgression++;
            }

            timesUp();

        }

        void BarreChrono::timesUp(){
            _enCours = false;
            _vue.finPartie();
        }

    }
}