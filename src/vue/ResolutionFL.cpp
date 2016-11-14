#include "ResolutionFL.hpp"
#include "Presentateur.hpp"

#include <string>

namespace froppieLand{
    namespace vue{

        ResolutionFL::ResolutionFL(FroppieVue& vue, Glib::ustring titre
            , const unsigned int& resoMin
            , const unsigned int& resoMax
            , const unsigned int& resoCourant)
            : Gtk::Frame(titre)
            , _resoMin(resoMin)
            , _resoMax(resoMax)
            , _vue(&vue)
            , _sButtons(
                Gtk::Adjustment::create
                (
                resoCourant
                , _resoMin
                , _resoMax
                , 1.0
                , 1.0
                , 0.0))
            , _manager(Gtk::ORIENTATION_HORIZONTAL){
                
                //_sButtons.set_adjustment(ajustement);

                auto chargeur = sigc::mem_fun(*this, &ResolutionFL::cbNouvelleResolution);

                _sButtons.signal_value_changed().connect(chargeur);

                _manager.pack_start(_sButtons, Gtk::PACK_SHRINK);

                add(_manager);

                show_all_children();
        }

        void ResolutionFL::cbNouvelleResolution(){
            _vue->cbPreparation();
        }

        const unsigned int ResolutionFL::getResolution()const{
            return static_cast< unsigned int>(_sButtons.get_value());
        } 
    }
}