#ifndef FROPP_HEALTH_HPP
#define FROPP_HEAlTH_HPP

#include <gtkmm/frame.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/label.h>

#include "include/FroppieVue.hpp"

namespace froppieLand{
    namespace vue{

        class FroppHealth: public Gtk::Frame{

        public:

            FroppHealth(FroppieVue& vue, Glib::ustring titre);

            FroppHealth(const FroppHealth&) = delete;

            FroppHealth& operator=(const FroppHealth&) = delete;

            void majFroppHealth(const Presentateur& presentateur);

        public:

            const FroppieVue& getVue()const;

        protected:

            FroppieVue* _vue; 

            Gtk::Image _coeur;

            Gtk::Label _labelPdv;

        };
    }
}

#endif