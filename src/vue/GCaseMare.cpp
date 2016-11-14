#include "GCaseMare.hpp"
#include "GGrill.hpp"
#include "FroppieVue.hpp"
#include "Presentateur.hpp"
#include "Self.hpp"

namespace froppieLand{
    namespace vue{

        GCaseMare::GCaseMare(GGrill& gGrill, unsigned int& ligne, unsigned int& colonne)
            :_gGrill(gGrill)
            , _ligne(ligne)
            , _colonne(colonne)
            , _connexion(nullptr){
            
                FroppieVue& vue = _gGrill.getModifVue();

            {
                typedef std::shared_ptr < Gtk::Image > PImage;

                PImage gnenurouge = PImage(new Gtk::Image(FroppieVue::getImage("grand-nenu-rouge")));
                PImage mnenurouge = PImage(new Gtk::Image(FroppieVue::getImage("moyen-nenu-rouge")));
                PImage pnenurouge = PImage(new Gtk::Image(FroppieVue::getImage("petit-nenu-rouge")));

                _formes["Dopant"]["Grand"] = gnenurouge;
                _formes["Dopant"]["Moyen"] = mnenurouge;
                _formes["Dopant"]["Petit"] = pnenurouge;

                _formes["Mortel"]["Grand"] = gnenurouge;
                _formes["Mortel"]["Moyen"] = mnenurouge;
                _formes["Mortel"]["Petit"] = pnenurouge;

                PImage gnenuvert = PImage(new Gtk::Image(FroppieVue::getImage("grand-nenu-vert")));

                _formes["Normal"]["Grand"] = gnenuvert;
                _formes["Normal"]["Moyen"] = PImage(new Gtk::Image(FroppieVue::getImage("moyen-nenu-vert")));
                _formes["Normal"]["Petit"] = PImage(new Gtk::Image(FroppieVue::getImage("petit-nenu-vert")));

                _formes["Immortel"]["Grand"] = gnenuvert;

                _formes["Veneneux"]["Grand"] = PImage(new Gtk::Image(FroppieVue::getImage("grand-nenu-jaune")));
                _formes["Veneneux"]["Moyen"] = PImage(new Gtk::Image(FroppieVue::getImage("moyen-nenu-jaune")));
                _formes["Veneneux"]["Petit"] = PImage(new Gtk::Image(FroppieVue::getImage("petit-nenu-jaune")));

                _formes["Nutritif"]["Grand"] = PImage(new Gtk::Image(FroppieVue::getImage("grand-nenu-rose")));
                _formes["Nutritif"]["Moyen"] = PImage(new Gtk::Image(FroppieVue::getImage("moyen-nenu-rose")));
                _formes["Nutritif"]["Petit"] = PImage(new Gtk::Image(FroppieVue::getImage("petit-nenu-rose")));

                _formes["Eau"]["Inexistant"] = PImage(new Gtk::Image(FroppieVue::getImage("eau")));
                

            }

            _froppieFormes["Malade"] = std::unique_ptr < Gtk::Image >(new Gtk::Image(FroppieVue::getImage("froppie-malade")));
            _froppieFormes["Sain"] = std::unique_ptr < Gtk::Image >(new Gtk::Image(FroppieVue::getImage("froppie-verte")));
            _froppieFormes["Mort"] = std::unique_ptr < Gtk::Image >(new Gtk::Image(FroppieVue::getImage("froppie-morte")));

            majCase(vue.getModifPresentateur());
        }

        GCaseMare::~GCaseMare(){
            _connexion = nullptr;
        }

        const unsigned int& GCaseMare::getLigne()const{
            return _ligne;
        }

        const unsigned int& GCaseMare::getColonne()const{
            return _colonne;
        }

        const GGrill& GCaseMare::getGGrill()const{
            return _gGrill;
        }

        void GCaseMare::majCase(presentateur::Presentateur& presentateur){

            const bool froppiePres = presentateur.isFroppied(_ligne, _colonne);        

            if(froppiePres) {
                const std::string fropEtat = presentateur.getEtatFroppie();

                Gtk::Image& rep = *_froppieFormes[fropEtat];

                if(&rep == get_child()) return;

                remove();
                add(rep);
            }
            else{

                const std::string type = presentateur.getTypeNenu(_ligne, _colonne);
                const std::string etat = presentateur.getEtatNenu(_ligne, _colonne);

                Gtk::Image& rep = *_formes[type][etat];

                if(&rep == get_child()) return;

                remove();
                add(rep);
            }
            
            show_all_children();
        }
 
        void GCaseMare::defaultClickHandler(){

            if(_connexion != nullptr)_connexion->disconnect();

            _directionClick = &presentateur::Presentateur::Self::getSelf();

        }


        bool GCaseMare::cbClickSouris(GdkEventButton* evt){

            FroppieVue& vue = _gGrill.getModifVue();

            presentateur::Presentateur& pres = vue.getModifPresentateur();

            if(!pres.deplaceFroppie(*_directionClick)) return true;

            _gGrill.disableMove();

            pres.setCaseMouvementPoss();

            _gGrill.actualiserCases();

            return true;
        }

        void GCaseMare::setMouvement(modele::Direction const* direction){

            if(_connexion != nullptr)_connexion->disconnect();

            _directionClick = direction;
                    
            auto chargeur = sigc::mem_fun(*this, &GCaseMare::cbClickSouris);

            _connexion = new sigc::connection(signal_button_press_event().connect(chargeur));

        }
        
    }
}