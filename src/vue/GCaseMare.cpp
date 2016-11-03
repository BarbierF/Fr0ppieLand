#include "include/GCaseMare.hpp"



namespace froppieLand{
    namespace vue{

        GCaseMare::GCaseMare(GGrill& gGrill, unsigned int ligne, unsigned int colonne, bool froppiePresente = false)
            :_gGrill(gGrill), _ligne(ligne), _colonne(colonne), _froppiePresente(froppiePresente){
            
            const FroppieVue& vue = gGrill.getFroppieVue();

            _formes = new std::map < std::string, std::map < std::string, std::shared_ptr< Gtk::image > > >();

            {

                typedef std::shared_ptr < Gtk::Image > PImage;

                PImage gnenurouge = PImage(vue.getImage("grand-nenu-rouge"));
                PImage mnenurouge = PImage(vue.getImage("moyen-nenu-rouge"));
                PImage pnenurouge = PImage(vue.getImage("petit-nenu-rouge"));

                _formes["Dopant"]["Grand"] = gnenurouge;
                _formes["Dopant"]["Moyen"] = mnenurouge;
                _formes["Dopant"]["Petit"] = pnenurouge;

                _formes["Mortel"]["Grand"] = gnenurouge;
                _formes["Mortel"]["Moyen"] = mnenurouge;
                _formes["Mortel"]["Petit"] = pnenurouge;

                PImage gnenuvert = PImage(vue.getImage("grand-nenu-vert"));

                _formes["Normal"]["Grand"] = gnenuvert;
                _formes["Normal"]["Moyen"] = mnenuvert;
                _formes["Normal"]["Petit"] = pnenuvert;

                _formes["Immortel"]["Grand"] = gnenuvert;

                _formes["Veneneux"]["Grand"] = PImage(vue.getImage("grand-nenu-jaune"));
                _formes["Veneneux"]["Moyen"] = PImage(vue.getImage("moyen-nenu-jaune"));
                _formes["Veneneux"]["Petit"] = PImage(vue.getImage("petit-nenu-jaune"));

                _formes["Nutritif"]["Grand"] = PImage(vue.getImage("grand-nenu-rose"));
                _formes["Nutritif"]["Moyen"] = PImage(vue.getImage("moyen-nenu-rose"));
                _formes["Nutritif"]["Petit"] = PImage(vue.getImage("petit-nenu-rose"));

                _formes["Eau"]["Inexistant"] = PImage(vue.getImage("eau"));
                

            }

            _froppieFormes = new std::map < std::string, std::unique_ptr < Gtk::Image > >();

            _froppieFormes["Malade"] = std::unique_ptr < Gtk::Image >(vue.getImage("froppie-malade"));
            _froppieFormes["Sain"] = std::unique_ptr < Gtk::Image >(vue.getImage("froppie-verte"));
            _froppieFormes["Morte"] = std::unique_ptr < Gtk::Image >(vue.getImage("froppie-morte"));

            _directionClick = Presentateur::Self::getSelf();

            mettreAJour(vue.getPresentateur());
        }

        const unsigned int getLigne()const{
            return _ligne;
        }

        const unsigned int getColonne()const{
            return _colonne;
        }

        const GGrill& getGGrill()const{
            return _gGrill;
        }

        void GCaseMare::mettreAJour(const Presentateur& presentateur){

            const std::string type = presentateur.typeNenu(_ligne, _colonne);
            const std::string etat = presentateur.etatNenu(_ligne, _colonne);
            const bool froppiePres = presentateur.isFroppied(_ligne, _colonne);


            if(froppiePres && etat == "Inexistant" && type == "eau") presentateur.OMGFroppieIsGettingEaten(_ligne, _colonne);

            Gtk::Image& rep = *_formes[type][etat];

            if(&rep == get_child()) return;

            remove();
            add(rep);

            _directionClick = &Presentateur::Self::getSelf();

            if(froppiePres) {
                const std::string fropEtat = presentateur._etatFroppie();

                add(*_froppieFormes[fropEtat]);
            }
            else if(presentateur.isPossibleMove(_ligne, _colonne)){

                auto chargeur = sigc::men_fun(*this, &GCaseMare::cbClickSouris);

                _directionClick = &presentateur.getDerniereDireFroppieVoisin();

                signal_button_press_event().connect(chargeur);
            }
            else{
                auto chargeur = sigc::men_fun(*this, on_button_press_event());

                signal_button_press_event().connect(chargeur);
            }

            rep.show();
        }

        void GCaseMare::vieillirCase(Presentateur& presentateur)const{

            presentateur.vieillirCase(_ligne, _colonne);

            mettreAJour(presentateur);
        }


        bool GCaseMare::cbClickSouris(GdkEventButton* evt){

            FroppieVue& vue = _gGrill.getModifVue();

            Presentateur& pres = vue.getModifPresentateur();

            pres.deplaceFroppie(_directionClick);

            _gGrill.actualiserCases();

            return true;
        }

    }
}