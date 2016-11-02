#include "include/ResolutionFL.hpp"


namespace froppieLand{
    namespace vue{

        ResolutionFL::ResolutionFL(FroppieVue& vue, Glib::ustring titre)
            : Gtk::Frame(titre), _vue(&vue){
            
            const Presentateur& presentateur = _vue.getPresentateur();

            _minReso = presentateur.getResolutionMin();
            _maxReso = presentateur.getResolutionMax();

            for(int i = _resoMin ; i <= _resoMax ; i++){

                Glib::ustring item(i):
                _menuResolution.append(Gtk::MenuItem(item));
            }

            _menuResolution.signal_selection_done(sigc::men_fun(*this, &ResolutionFL::nouvelleResolution));
        }

        void ResolutionFL::cdNouvelleResolution(){
            _vue->nouvellePartie();
        }

        const unsigned int& getResolution()const{
            return _menuResolution().get_active().get_label();
        } 
    }
}