#include <chrono>

#include "BarreChrono.hpp"
#include "FroppieVue.hpp"

#include <iostream>

namespace froppieLand{
    namespace vue{

        BarreChrono::BarreChrono(FroppieVue& vue, Glib::ustring titre
            , const unsigned int& tempsChrono, const unsigned int& tempsViellissement)
            :Gtk::Frame(titre), _vue(vue)
            , _enCours(false)
            , _secondeTime(0)
            , _tempsChrono(tempsChrono)
            , _tempsVieillissement(tempsViellissement)
            , _manager(Gtk::ORIENTATION_HORIZONTAL){
            
            add(_manager);

            _barProgression.set_fraction(0);

            Glib::ustring libelle(0 + "secondes");
            _barProgression.set_text(libelle);

            _manager.pack_start(_barProgression, Gtk::PACK_EXPAND_WIDGET);

            show_all_children();
        }

        void BarreChrono::progression(){

            double pas = static_cast < double >(_tempsVieillissement) / static_cast < double >(_tempsChrono);
            double valSuivante = _barProgression.get_fraction() + pas;

            //On veut éviter les erreurs donc si on dépasse on remet à zéro
            if(valSuivante > 1.0) valSuivante = 0.0; 

            _barProgression.set_fraction(valSuivante);
            
            _barProgression.set_text(Glib::ustring(std::to_string(pas)) + " secondes");
        }

        void BarreChrono::startChrono(){

            if(!_enCours){
                _secondeTime = 0;

                sigc::slot<bool> slot = sigc::bind(sigc::mem_fun(*this
                    ,  &BarreChrono::traitementTimer), 0);

                sigc::connection connection = Glib::signal_timeout().connect(
                    slot
                    , 1000);

                _timer = connection;
                _enCours = true;            
            }
        }

        void BarreChrono::resetChrono(){
            if(!_enCours) return;
            _barProgression.set_fraction(0);
            startChrono();
        }

        void BarreChrono::stopChrono(){

            if(!_enCours) return;
            _barProgression.set_fraction(0);
            _enCours = false;
            _timer.disconnect();
        }
        //ne fonctionnera pas
        bool BarreChrono::traitementTimer(int t_number){
            if(_enCours){
                progression();
                _vue.leTempsPasse();

                _secondeTime++;

                if(_secondeTime > _tempsChrono) timesUp();
            }
            return true;
        }

        void BarreChrono::timesUp(){
            _enCours = false;
            _vue.finPartie(false);
        }

    }
}