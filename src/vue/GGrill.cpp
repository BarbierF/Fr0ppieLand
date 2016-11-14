#include "GGrill.hpp"
#include "Grill.hpp"
#include "FroppieVue.hpp"
#include "Presentateur.hpp"

namespace froppieLand{
    namespace vue{

        GGrill::GGrill(FroppieVue& vue)
            :_vue(vue){

            add(_mareManager);

            const presentateur::Presentateur& pres = _vue.getPresentateur();
            const unsigned int& taille = pres.getDimension();

            _mare.reserve(taille * taille);

            for(unsigned int i = 0 ; i < taille ; i++){
                for(unsigned int j = 0 ; j < taille ; j++){
                    GCaseMare* case_mare = Gtk::manage(new GCaseMare(*this, i, j));
                    _mareManager.attach(*case_mare, j, i, 1, 1);
                    _mare.push_back(case_mare);
                }
            }
            
        }

        const FroppieVue& GGrill::getVue()const{
            return _vue;
        }


        FroppieVue& GGrill::getModifVue(){
            return _vue;
        }

        void GGrill::disableMove(){
            for(GCaseMare* case_mare : _mare){
                case_mare->defaultClickHandler();
            }
        }

        void GGrill::setCaseMouvable(const unsigned int& ligne, const unsigned int& colonne, const GCaseMare::Direction* direction){
            const presentateur::Presentateur& pres = _vue.getPresentateur();
            const unsigned int& taille = pres.getDimension();
            
            _mare[ligne * taille + colonne]->setMouvement(direction);
        }

        void GGrill::actualiserCases(){
            for(GCaseMare* case_mare : _mare){
                case_mare->majCase(_vue.getModifPresentateur());
            }
        }

    }
}