#include "FroppieVue.hpp"
#include "Presentateur.hpp"
#include <iostream>

namespace froppieLand{
    namespace vue{

        const Glib::ustring FroppieVue::_nomVue("Fr0ppieLand");

        const Glib::ustring FroppieVue::_nomPdvFroppie("Points de vie :");

        const Glib::ustring FroppieVue::_nomResolution("Resolution de la mare :");

        const Glib::ustring FroppieVue::_nomBarreChrono("Durée de vie des nénuphars");

        const Glib::ustring FroppieVue::_cheminImages("./src/ressources/images/");

        std::map < Glib::ustring, Glib::RefPtr < Gdk::Pixbuf > > FroppieVue::_images;

        FroppieVue::FroppieVue(presentateur::Presentateur& presentateur)
            : _presentateur(presentateur)
            , _ptrGrillGraphic(new GGrill(*this))
            , _pdvFroppie(*this, _nomPdvFroppie)
            , _resoTerrain(*this, _nomResolution, presentateur.getResolutionMin(), presentateur.getResolutionMax(), presentateur.getDimension())
            , _chronometre(*this, _nomBarreChrono, presentateur.getTempsPartie(), presentateur.getTempsVieillissement())
            , _centManager(Gtk::ORIENTATION_HORIZONTAL)
            , _infManager(Gtk::ORIENTATION_HORIZONTAL)
            {

                set_title(_nomVue);

                Gtk::Box* manager = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

                add(*manager);

                buildBarreOutils(*manager);

                buildPartieMillieu(*manager);

                buildPartieInferieur(*manager);

                set_resizable(false);

                show_all_children();

        }

        void FroppieVue::initialiser(){

            //Création des PixBuf permettant d'avoir accès aux images du jeu
            _images["coeur"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "coeur.png");

            _images["coeur96x91"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "coeur-96x91.png");

            _images["eau"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "eau-96x96.png");

            _images["grand-nenu-jaune"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "grand-nenuphare-jaune-96x96.png");

            _images["grand-nenu-rose"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "grand-nenuphare-rose-96x96.png");

            _images["grand-nenu-rouge"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "grand-nenuphare-rouge-96x96.png");

            _images["grand-nenu-vert"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "grand-nenuphare-vert-96x96.png");

            _images["moyen-nenu-jaune"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "moyen-nenuphare-jaune-96x96.png");

            _images["moyen-nenu-rose"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "moyen-nenuphare-rose-96x96.png");

            _images["moyen-nenu-rouge"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "moyen-nenuphare-rouge-96x96.png");

            _images["moyen-nenu-vert"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "moyen-nenuphare-vert-96x96.png");

            _images["petit-nenu-jaune"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "petit-nenuphare-jaune-96x96.png");

            _images["petit-nenu-rose"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "petit-nenuphare-rose-96x96.png");

            _images["petit-nenu-rouge"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "petit-nenuphare-rouge-96x96.png");

            _images["petit-nenu-vert"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "petit-nenuphare-vert-96x96.png");

            _images["froppie-verte"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "froppie_vert96x96.png");

            _images["froppie-malade"] = 
                Gdk::Pixbuf::create_from_file(_cheminImages + "froppie_malade96x96.png");

            _images["froppie-morte"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "froppie_morte96x96.png");

            _images["very_doge"] =
                Gdk::Pixbuf::create_from_file(_cheminImages + "doge.png");
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

        const presentateur::Presentateur& FroppieVue::getPresentateur()const{
            return _presentateur;
        }

        presentateur::Presentateur& FroppieVue::getModifPresentateur(){
            return _presentateur;
        }

        void FroppieVue::buildBarreOutils(Gtk::Box& manager){
            
            Glib::RefPtr< Gtk::ActionGroup > groupe_actions = Gtk::ActionGroup::create();

            groupe_actions->add(Gtk::Action::create("CommandeMenu", "Commandes"));

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::Action::create(
                    "CommandePreparer",
                    Gtk::Stock::ADD,
                    "Nouvelle Partie",
                    "Préparer une nouvelle partie de Fr0ppieLAnd"
                );

                auto chargeur = sigc::mem_fun(*this, &FroppieVue::cbPreparation);
                groupe_actions->add(action, chargeur);
            }

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::Action::create(
                    "CommandeLancer",
                    Gtk::Stock::APPLY,
                    "Lancer Partie",
                    "Lancer la partie de Fr0ppieLand"
                );

                auto chargeur = sigc::mem_fun(*this, &FroppieVue::cbLancement);
                groupe_actions->add(action, chargeur);
            }

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::Action::create(
                    "CommandeQuitter",
                    Gtk::Stock::QUIT,
                    "Quitter",
                    "Quitter l'application'"
                );

                auto chargeur = sigc::mem_fun(*this, &FroppieVue::cbQuitter);
                groupe_actions->add(action, chargeur);
            }

            {
                Glib::RefPtr< Gtk::Action > action = Gtk::Action::create(
                    "CommandePresenter",
                    Gtk::Stock::ABOUT,
                    "A propos.",
                    "Présenter l'application.'"
                );

                auto chargeur = sigc::mem_fun(*this, &FroppieVue::cbPresentation);
                groupe_actions->add(action, chargeur);
            }

            Glib::RefPtr< Gtk::UIManager > ui_manager = Gtk::UIManager::create();
            ui_manager->insert_action_group(groupe_actions);
            add_accel_group(ui_manager->get_accel_group());

            const Glib::ustring structure_groupe =
            "<ui>"
            "   <menubar name='BarreMenus'>"
            "       <menu action='CommandeMenu'>"
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
            "</ui>";

            ui_manager->add_ui_from_string(structure_groupe);

            Gtk::Widget* ptrBarreMenus = ui_manager->get_widget("/BarreMenus");
            if(ptrBarreMenus != nullptr)
                manager.pack_start(*ptrBarreMenus, Gtk::PACK_SHRINK);

            Gtk::Widget* ptrBarreOutils = ui_manager->get_widget("/BarreOutils");
            if(ptrBarreOutils != nullptr)
                manager.pack_start(*ptrBarreOutils, Gtk::PACK_SHRINK);
        }

        void FroppieVue::buildPartieMillieu(Gtk::Box& manager){
            
            manager.add(_centManager);

            _centManager.pack_start(_pdvFroppie, Gtk::PACK_EXPAND_WIDGET);

            _centManager.pack_start(*_ptrGrillGraphic, Gtk::PACK_SHRINK);

        }

        void FroppieVue::buildPartieInferieur(Gtk::Box& manager){

            manager.add(_infManager);

            _infManager.pack_start(_resoTerrain, Gtk::PACK_SHRINK);

            _infManager.pack_start(_chronometre, Gtk::PACK_EXPAND_WIDGET);
        }

        void FroppieVue::cbPresentation(){

            Gtk::AboutDialog apropos;
            apropos.set_transient_for(*this);
            apropos.set_program_name("Fr0ppieLand");
            apropos.set_version("0.0.1");
            apropos.set_copyright("Fr0ppieGroup - very_froppie@outlook.fr");
            apropos.set_comments("Devoir continu de Programmation et Parrallèlisme");
            apropos.set_authors(
                {
                    "Florentin Barbier",
                    "Alexandre Outrequin",
                    "Hugo Dupuy-Roudel",
                    "Florian Chollet"
                }
            );
            apropos.set_logo(_images["very_doge"]);

            apropos.run();

            apropos.hide();
        }

        void FroppieVue::cbQuitter(){
            _chronometre.stopChrono();
            hide();
        }

        void FroppieVue::cbLancement(){
            _presentateur.genererTerrain();
            _chronometre.startChrono();
            _ptrGrillGraphic->actualiserCases();
        }

        void FroppieVue::cbPreparation(){
            _presentateur.nouveauJeu(_resoTerrain.getResolution());
            
            _centManager.remove(*_ptrGrillGraphic);
            _ptrGrillGraphic.reset(new GGrill(*this));

            _centManager.pack_end(*_ptrGrillGraphic);

            show_all_children();
        }

        void FroppieVue::afficherPdvFroppie(){

            _pdvFroppie.majFroppHealth(_presentateur);
        }

        void FroppieVue::leTempsPasse(){
            _presentateur.vieillirCases();
            _presentateur.genererTerrain();

            _ptrGrillGraphic->actualiserCases();
        }

        void FroppieVue::finPartie(){
            _pdvFroppie.majFroppHealth(_presentateur);
            _ptrGrillGraphic->actualiserCases();
            _chronometre.stopChrono();
        }

        const Glib::RefPtr< Gdk::Pixbuf >& FroppieVue::getImage(const Glib::ustring& nom){
            return _images[nom];
        }
    }
}