#ifndef FROPPIE_VUE_HPP
#define FROPPIE_VUE_HPP

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/box.h>
#include <gtkmm/stock.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/cellrendererpixbuf.h>

#include <map>

#include "FroppHealth.hpp"
#include "BarreChrono.hpp"
#include "ResolutionFL.hpp"
#include "GGrill.hpp"

namespace froppieLand{

    namespace presentateur{
        class Presentateur;
    }


    namespace vue{

        class FroppieVue: public Gtk::Window{
        public:

            friend class FroppHealth;
            friend class GGrill;
            friend class ResolutionFL;
            friend class BarreChrono;
            friend class GCaseMare;

        public:

            FroppieVue(presentateur::Presentateur&);

            FroppieVue(const FroppieVue&) = delete;

            FroppieVue& operator=(const FroppieVue&) = delete;

            static void initialiser();

        public:

            const presentateur::Presentateur& getPresentateur()const;

            presentateur::Presentateur& getModifPresentateur();

            static const Glib::ustring getNomVue();

            static const Glib::ustring getNomPdvFroppie();

            static const Glib::ustring getNomResolution();

            static const Glib::ustring getNomBarreChrono();

            static const Glib::ustring getCheminImages();

        protected:

            static const Glib::RefPtr< Gdk::Pixbuf >& getImage(const Glib::ustring& nom);

            void leTempsPasse();

            void finPartie();

        protected:

            void cbPresentation();

            void cbQuitter();

            void cbLancement();

            void cbPreparation();

            void buildBarreOutils(Gtk::HBox& manager);

            void buildPartieMillieu(Gtk::HBox& manager);

            void buildPartieInferieur(Gtk::HBox& manager);

        private:

            static std::map < Glib::ustring, Glib::RefPtr < Gdk::Pixbuf > > _images;

            static const Glib::ustring _nomVue;

            static const Glib::ustring _nomPdvFroppie;

            static const Glib::ustring _nomResolution;

            static const Glib::ustring _nomBarreChrono;

            static const Glib::ustring _cheminImages;

        protected:

            presentateur::Presentateur& _presentateur;

            std::unique_ptr< GGrill > _ptrGrillGraphic;

            FroppHealth _pdvFroppie;

            ResolutionFL _resoTerrain;

            BarreChrono _chronometre;

            Gtk::VBox _centManager;

            Gtk::VBox _infManager;
        };
    }
}

#endif