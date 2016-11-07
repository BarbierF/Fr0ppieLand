#include "ResolutionFL.hpp"
#include "Presentateur.hpp"

#include <string>
#include <iostream>

namespace froppieLand{
    namespace vue{

        ResolutionFL::ResolutionFL(FroppieVue& vue, Glib::ustring titre
            , const unsigned int& resoMin
            , const unsigned int& resoMax)
            : Gtk::Frame(titre)
            , _resoMin(resoMin)
            , _resoMax(resoMax)
            , _vue(&vue){

                std::cout << "DEbut construction resolutionFL" << std::endl;
                _menuResolution.reparent(_manager);

                for(unsigned int i = _resoMin ; i <= _resoMax ; i++){
                    std::cout << "Debut boucle" << std::endl;
                    Glib::ustring sItem(std::to_string(i));
                    Gtk::MenuItem mItem(sItem);
                    _menuResolution.append(mItem);

                    std::cout << "Fin iteration" << std::endl;
                }

                auto chargeur = sigc::mem_fun(*this, &ResolutionFL::cbNouvelleResolution);

                _menuResolution.signal_selection_done().connect(chargeur);
        
                _manager.show();

                std::cout << "Fin construction resolutionFL" << std::endl;
        }

        void ResolutionFL::cbNouvelleResolution(){
            _vue->cbPreparation();
        }

        const unsigned int ResolutionFL::getResolution()const{
            return std::stoul(_menuResolution.get_active()->get_label());
        } 
    }
}