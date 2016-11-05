#include "FroppHealth.hpp"
#include "FroppieVue.hpp"
#include "Presentateur.hpp"


namespace froppieLand{
    namespace vue{

        FroppHealth::FroppHealth(FroppieVue& vue, Glib::ustring titre)
            :Gtk::Frame(titre), _vue(vue), _coeur(new Gtk::Image(vue.getImage("coeur"))){
            
            add(_manager);

            const presentateur::Presentateur& presentateur = vue.getPresentateur();

            majFroppHealth(presentateur);
        }


        void FroppHealth::majFroppHealth(const presentateur::Presentateur& presentateur){

            _manager.remove(_labelPdv);
            _manager.remove(*_coeur);

            Glib::ustring pdv(std::to_string(presentateur.getVieFroppie()));

            _labelPdv.set_text(pdv);

            _manager.pack_start(*_coeur, Gtk::PACK_SHRINK);

            _labelPdv.set_text(std::to_string(presentateur.getVieFroppie()));

            _manager.pack_start(_labelPdv, Gtk::PACK_SHRINK);

            _coeur->show();
            _labelPdv.show();

        }

        void FroppHealth::setImage(const presentateur::Presentateur& presentateur,
            const Glib::ustring& image){

            _coeur.reset(new Gtk::Image(_vue.getImage(image)));

            majFroppHealth(presentateur);
        }
    }
}