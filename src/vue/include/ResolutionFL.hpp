#ifndef RESOLUTION_FL_HPP
#define RESOLUTION_FL_HPP

#include <gtkmm/frame.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/adjustment.h>
#include <glibmm/main.h>

namespace froppieLand{
    namespace vue{

        class FroppieVue;

        class ResolutionFL: public Gtk::Frame{
        
        public:
        
            ResolutionFL(FroppieVue& vue, Glib::ustring titre
                , const unsigned int& resoMin
                , const unsigned int& resoMax
                , const unsigned int& resoCourant);

            ResolutionFL(const ResolutionFL&) = delete;

            ResolutionFL& operator=(const ResolutionFL&) = delete;

            const unsigned int getResolution()const;

        protected:

            void cbNouvelleResolution();   //méthode sur le signal_selection_done

        protected:

            unsigned int _resoMin, _resoMax;
        
            FroppieVue* _vue;

            Gtk::SpinButton _sButtons;

            Gtk::Box _manager;

        };
    }
}

#endif