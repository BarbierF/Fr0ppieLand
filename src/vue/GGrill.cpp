#include "GGrill.hpp"


namespace froppieLand{
    namespace vue{

        GGrill::GGrill(FroppieVue& vue)
            :_vue(vue){

            add(_mareManager);

            const Presentateur& pres = _vue.getPresentateur();

            const Grill& grill = pres.getModele();

            const unsigned int& taille = grill.getTaille();

            _mare.resize(taille);

            for(int i = 0 ; i < taille ; i++){
                for(int j = 0 ; j < taille ; j++){
                    GCaseMare* case_mare = Gtk::manage(new GCaseMare(*this, i, j));
                    _gestionnaire.attach(*case_mare, i, j, 1, 1);
                    _mare.push_back(case_mare);
                }
            }
            
        }

        const FroppieVue& GGrill::getVue()const{
            return _vue;
        }

        FroppieVue& GGrill::getModifVue()const{
            return _vue;
        }

        void GGrill::activerDeplacement(){
            for(GCaseMare* case_mare : _mare){
                case_mase->activerDeplacement(_vue.getPresentateur());
            }
        }

        void GGrill::actualiserCases(){
            for(GCaseMare* case_mare : _mare){
                case_mare->mettreAJour(_vue.getPresentateur());
            }
        }

    }
}