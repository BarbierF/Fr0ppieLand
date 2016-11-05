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

            _mare.resize(taille);

            for(unsigned int i = 0 ; i < taille ; i++){
                for(unsigned int j = 0 ; j < taille ; j++){
                    GCaseMare* case_mare = Gtk::manage(new GCaseMare(*this, i, j));
                    _mareManager.attach(*case_mare, i, j, 1, 1);
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

        void GGrill::actualiserCases(){
            for(GCaseMare* case_mare : _mare){
                case_mare->majCase(_vue.getModifPresentateur());
            }
        }

        void GGrill::vieillirCases(){
            presentateur::Presentateur& pres = _vue.getModifPresentateur();
            const unsigned int& dimension = pres.getDimension(); 

            for(unsigned int i = 0 ; i < dimension ; i++){
                for(unsigned int j = 0 ; j < dimension ; j++)
                    pres.vieillirCase(i, j);
            }

            actualiserCases();
        }

    }
}