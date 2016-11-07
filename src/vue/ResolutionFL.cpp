#include "ResolutionFL.hpp"
#include "Presentateur.hpp"

#include <string>
#include <iostream>

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

                std::cout << "DEbut construction resolutionFL" << std::endl;

                
                std::cout << resoCourant << std::endl;
                
                //_sButtons.set_adjustment(ajustement);

                auto chargeur = sigc::mem_fun(*this, &ResolutionFL::cbNouvelleResolution);

                _sButtons.signal_value_changed().connect(chargeur);

                _manager.pack_start(_sButtons, Gtk::PACK_SHRINK);

                add(_manager);

                std::cout << "Fin construction resolutionFL" << std::endl;

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