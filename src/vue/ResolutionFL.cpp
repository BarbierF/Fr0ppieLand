#include "include/ResolutionFL.hpp"


namespace froppieLand{
    namespace vue{

        ResolutionFL::ResolutionFL(FroppieVue& vue, Glib::ustring titre)
            : Gtk::Frame(titre), _vue(&vue), _resoMin(3), _resoMax(10){
            
            for(int i = _resoMin ; i <= _resoMax ; i++){

                Glib::ustring item(i):
                _menuResolution.append(Gtk::MenuItem(item));
            }

            _menuResolution.signal_selection_done(sigc::men_fun(*this, &ResolutionFL::nouvelleResolution));
        }

        ResolutionFL::Resolution(FroppieVue& vue, Glib::ustring titre, const unsigned int resoMin, const unsigned int resoMax)
            : Gtk::Frame(titre), _vue(&vue), _resoMin(resoMin), _resoMax(resoMax){
            
            for(int i = _resoMin ; i <= _resoMax ; i++){

                Glib::ustring item(i):
                _menuResolution.append(Gtk::MenuItem(item));
            }

            _menuResolution.signal_selection_done(sigc::men_fun(*this, &ResolutionFL::nouvelleResolution));

        }

        void ResolutionFL::nouvelleResolution(){

            _vue->nouvellePartie(
                _menuResoltion.get_active().get_label();
            );
        }
    }
}