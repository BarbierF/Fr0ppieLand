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

            FroppHealth(const FroppieVue& vue);

            void majFroppHealth(const Presentateur& presentateur);

        public:

            const FroppieVue& getVue()const;

        protected:

            const FroppieVue _vue; 

            Gtk::Image _coeur;

            Gtk::Label _labelPdv;

        };
    }
}

#endif