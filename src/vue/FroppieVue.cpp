#include "Presentateur.hpp"


namespace froppieLand{
    namespace vue{

        const Glib::ustring FroppieVue::_nomVue("Fr0ppieLand");

        const Glib::ustring FroppieVue::_nomPdvFroppie("Points de vie :");

        const Glib::ustring FroppieVue::_nomResolution("Resolution de la mare :");

        const Glib::ustring FroppieVue::_nomBarreChrono("Durée de vie des nénuphars");

        const Glib::ustring FroppieVue::_cheminImages("/src/ressources/images/");

        void FroppieVue::initialiser(){

            //Création des PixBuf permettant d'avoir accès aux images du jeu
            _images["coeur"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "coeur.png");

            _images["coeur96x91"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "coeur-96x91.png");

            _images["eau"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "eau-96x96.png");

            _images["grand-nenu-jaune"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "grand-nenuphare-jaune-96x96.png");

            _images["grand-nenu-rose"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "grand-nenuphare-rose-96x96.png");

            _images["grand-nenu-rouge"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "grand-nenuphare-rouge-96x96.png");

            _images["grand-nenu-vert"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "grand-nenuphare-vert-96x96.png");

            _images["moyen-nenu-jaune"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "moyen-nenuphare-jaune-96x96.png");

            _images["moyen-nenu-rose"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "moyen-nenuphare-rose-96x96.png");

            _images["moyen-nenu-rouge"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "moyen-nenuphare-rouge-96x96.png");

            _images["moyen-nenu-vert"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "moyen-nenuphare-vert-96x96.png");

            _images["petit-nenu-jaune"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "petit-nenuphare-jaune-96x96.png");

            _images["petit-nenu-rose"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "petit-nenuphare-rose-96x96.png");

            _images["petit-nenu-rouge"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "petit-nenuphare-rouge-96x96.png");

            _images["petit-nenu-vert"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "petit-nenuphare-vert-96x96.png");

            _images["froppie-verte"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "froppie_vert96x96.png");

            _images["froppie-malade"] = 
                Gdk::PixBuf::create_from_file(_cheminImages + "froppie_malade96x96.png");

            _images["froppie-morte"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "froppie_morte96x96.png");

            _images["very_doge"] =
                Gdk::PixBuf::create_from_file(_cheminImages + "doge.png");

        }

        const Glib::ustring FroppieVue::getNomVue(){
            return _nomVue;
        }

        const Glib::ustring FroppieVue::getNomPdvFroppie(){
            return _nomPdvFroppie;
        }

        const Glib::ustring FroppieVue::getNomResolution(){
            return _nomResolution;
        }

        const Glib::ustring FroppieVue::getNomBarreChrono(){
            return _nomBarreChrono;
        }

        const Glib::ustring FroppieVue::getCheminImages(){
            return _cheminImages;
        }

        const Presentateur& FroppieVue::getPresentateur()const{
            return _presentateur;
        }

        Presentateur FroppieVue::getModifPresentateur(){
            return _presentateur;
        }

        FroppieVue::FroppieVue(Presentateur& presentateur):
            _presentateur(presentateur), _ptrGrillGraphic(new GGrill(*this)), _pdvFroppie(*this, _nomPdvFroppie)
            , _resoTerrain(*this, _nomResolution, _presentateur.getMinReso(), _presentateur.getMaxReso())
            , _chronometre(*this, _nomBarreChrono){

                set_title(_nomVue);

                Gtk::VBox* manager = Gtk::manage(new Gtk::VBox());

                add(*manager);

                buildBarreOutils(*manager);

                buildPartieMillieu(*manager);

                buildPartieInferieur(*manager);

                set_resizable(false);

                show_all_children();
        }

        void FroppieVue::buildBarreOutil(Gtk::VBox& manager){
            
            Glib::RefPtr< Gtk::ActionGroups > groupe_actions = Gtk::ActionGroup::create();

            groupe_actions->add(Gtk::action::create("CommandeMenu", "Commandes"));

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::action::create(
                    "CommandePreparer",
                    Gtk::Stock::ADD,
                    "Nouvelle Partie",
                    "Préparer une nouvelle partie de Fr0ppieLAnd"
                );

                auto chargeur = sigc::men_fun(*this, &FroppieVue::cbPreparation);
                groupe_actions->add(action, chargeur);
            }

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::action::create(
                    "CommandeLancer",
                    Gtk::Stock::APPLY,
                    "Lancer Partie",
                    "Lancer la partie de Fr0ppieLand"
                );

                auto chargeur = sigc::men_fun(*this, &FroppieVue::cbLancement);
                groupe_actions->add(action, chargeur);
            }

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::action::create(
                    "CommandeQuitter",
                    Gtk::Stock::QUIT,
                    "Quitter",
                    "Quitter l'application'"
                );

                auto chargeur = sigc::men_fun(*this, &FroppieVue::cbQuitter);
                groupe_actions->add(action, chargeur);
            }

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::action::create(
                    "CommandePresenter",
                    Gtk::Stock::ABOUT,
                    "A propos.",
                    "Présenter l'application.'"
                );

                auto chargeur = sigc::mem_fun(*this, &FroppieVue::cbPresentation);
                groupe_actions->add(action, chargeur);
            }

            Glib::RefPtr< Gtk::UIManager > ui_manager = Gtk::UIManager::create();
            ui_manager->insert_action_group(groupe);
            add_accel_group(ui_manager->get_accell_group);

            const Glib::ustring structure_groupe =
            "<ui>"
            "   <menubar name='BarreMenus'>"
            "       <menu action='CommandesMenu'>"
            "           <menuitem action='CommandePreparer'/>"
            "           <menuitem action='CommandeLancer'/>"
            "           <menuitem action='CommandePresenter'/>"
            "           <menuitem action='CommandeQuitter'/>"
            "       </menu>"
            "   </menubar>"
            "   <toolbar name='BarreOutils'>"
            "       <toolitem action='CommandePreparer'/>"
            "       <toolitem action='CommandeLancer'/>"
            "       <toolitem action='CommandePresenter'/>"
            "       <toolitem action='CommandeQuitter'/>"
            "    </toolbar>"
            "</ui>"

            ui_manager->add_ui_from_string(structures);

            Gtk::Widget* ptrBarreMenus = ui_manager->get_widget("/BarreMenus");
            if(ptrBarreMenus != nullptr)
                manager.pack_start(*ptrBarreMenus, Gtk::PACK_SHRINK);

            Gtk::Widget* ptrBarreOutils = ui_manager->get_widget("/BarreOutils");
            if(ptrBarreOutils != nullptr)
                manager.pack_start(*ptrBarreOutils, Gtk::PACK_SHRINK);
        }

        void FroppieVue::buildPartieMillieu(Gtk::Box& manager){
            
            manager.add(_centManager);

            _centManager.pack_start(_pdvFroppie, Gtk::PACK);

            _centManager.pack_start(*_gGrill);

        }

        void FroppieVue::Inferieur(Gtk::Box manager){

            manager.add(_infManager);

            _infManager.pack_start(_resoTerrain);

            _infManager.pack_start(_chronometre);
        }

        void FroppieVue::cbPresentation(){

            Gtk::AboutDialog apropos;
            apropos.set_transient_for(*this);
            apropos.set_program_name("Fr0ppieLand");
            apropos.set_version("0.0.1");
            apropos.set_copyright("Fr0ppieGroup - very_froppie@outlook.fr");
            apropos.set_comment("Devoir continue de Programmation et Parrallèlisme");
            apropos.set_authors(
                {"Florentin Barbier"},
                {"Alexandre Outrequin"},
                {"Hugo Dupuy-Roudel"},
                {"Florian Chollet"}
            );
            apropos.set_logo(_images["very_doge"]);

            apropos.run();

            apropos.hide();
        }

        void FroppieVue::cbQuitter(){
            hide();
        }

        void FroppieVue::cbLancement(){
            _chronometre.startChrono();
            _ptrGrillGraphic->activerDeplacement();
        }

        void FroppieVue::cbPreparation(){
            _presentateur->nouveauJeu(_resoTerrain.getResolution());
            
            _centManager.remove(*ptrGrillGraphic);
            _ptrGrillGraphic.reset(new GGrill($this));

            _centManager.pack_start(*_ptrGrillGraphic);

            show_all_children();
        }

        void FroppieVue::leTempsPasse(){
            _ptrGrillGraphic.actualiserCases(_presentateur);
        }
    }
}