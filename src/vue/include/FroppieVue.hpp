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

namespace froppieLand{
    namespace vue{

        class Presentateur;

        class FroppieVue: public Gtk::Window{
        public:

            friend class GCaseMare;
            friend class FroppHealth;
            friend class GGrill;
            friend class ResolutionFL;
            friend class BarreChrono;

        public:

            FroppieVue(Presentateur&);

            FroppieVue(const FroppieVue&) = delete;

            FroppieVue& operator=(const FroppieVue&) = delete;

            void initialiser();

        public:

            const Presentateur& getPresentateur()const;

            Presentateur& getModifPresentateur();

            static const Glib::ustring getNomVue();

            static const Glib::ustring getNomPdvFroppie();

            static const Glib::ustring getNomResolution();

            static const Glib::ustring getNomBarreChrono();

            static const Glib::ustring getCheminImage();

        protected:

            static const Glib::RefPtr< Gdk::PixBuf >& getImage(const Glib::ustring& nom);

            void leTempsPasse();

        protected:

            void cbPresentation();

            void cbQuitter();

            void cbLancement();

            void cbPreparation();

            void buildBarreOutils(Gtk::VBox& manager);

            void buildPartieMillieu(Gtk::VBox& manager);

            void buildPartieInferieur(Gtk::VBox& manager);

        private:

            std:map < Glib::ustring, Glib::GRefPtr < Glib::GPixBuf > > _images;

            static const Glib::ustring _nomVue;

            static const Glib::ustring _nomPdvFroppie;

            static const Glib::ustring _nomResolution;

            static const Glib::ustring _nomBarreChrono;

            static const Glib::ustring _cheminImages;

        protected:

            std::unique_ptr< GGrill > _ptrGrillGraphic;

            FroppHealth _pdvFroppie;

            ResolutionFL _resoTerrain;

            BarreChrono _chronometre;

            Gtk::VBox _centManager;

            Gtk::VBox _infManager;

            Presentateur& presentateur;
        };
    }
}

#endif