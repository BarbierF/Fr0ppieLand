#include "ResolutionFL.hpp"
#include "Presentateur.hpp"

#include <string>

namespace froppieLand{
    namespace vue{

        ResolutionFL::ResolutionFL(FroppieVue& vue, Glib::ustring titre
            , const unsigned int& resoMin, const unsigned int& resoMax)
            : Gtk::Frame(titre), _vue(&vue), _resoMin(resoMin), _resoMax(resoMax){

                _manager.add(_menuResolution);

                for(int i = _resoMin ; i <= _resoMax ; i++){

                    Glib::ustring sItem(std::to_string(i));
                    Gtk::MenuItem mItem(sItem);
                    _menuResolution.append(mItem);
                }

                auto chargeur = sigc::mem_fun(*this, &ResolutionFL::cbNouvelleResolution);

                _menuResolution.signal_selection_done().connect(chargeur);
        
                _manager.show();
        }

        void ResolutionFL::cbNouvelleResolution(){
            _vue->cbPreparation();
        }

        const unsigned int ResolutionFL::getResolution()const{
            return std::stoul(_menuResolution.get_active()->get_label());
        } 
    }
}