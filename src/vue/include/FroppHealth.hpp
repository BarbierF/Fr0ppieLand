#ifndef FROPP_HEALTH_HPP
#define FROPP_HEAlTH_HPP

#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>

#include "Presentateur.hpp"

namespace froppieLand{
    namespace vue{

        class FroppieVue;

        class FroppHealth: public Gtk::Frame{

        public:

            FroppHealth(FroppieVue& vue, Glib::ustring titre);

            FroppHealth(const FroppHealth&) = delete;

            FroppHealth& operator=(const FroppHealth&) = delete;

            void majFroppHealth(const presentateur::Presentateur& presentateur);

        public:

            const FroppieVue& getVue()const;

        protected:

            FroppieVue* _vue; 

            const Gtk::Image _coeur;

            Gtk::Label _labelPdv;

        };
    }
}

#endif