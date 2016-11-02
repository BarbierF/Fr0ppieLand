#include "FroppHealth.hpp"


namespace froppieLand{
    namespace vue{

        FroppHealth::FroppHealth(FroppieVue& vue, Glib::ustring titre)
            :Gtk::Frame(titre), _vue(&vue){
            
            _coeur =_vue->getImage("coeur");

            remove();
            add(_coeur);

            add(_labelPdv);

            majFropHealth(_vue->getPresentateur());
        }


        void FroppHealth::majFropHealth(const Presentateur& presentateur){

            Gtk::ustring pdv(presentateur.getVieFroppie());

            _labelPdv.set_text(pdv);

        }

        const FroppieVue& getVue()const{
            return *_vue;
        }
    }
}