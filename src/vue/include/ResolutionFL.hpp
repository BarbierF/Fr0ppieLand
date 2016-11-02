#ifndef RESOLUTION_FL_HPP
#define RESOLUTION_FL_HPP

#include <gtkmm/frame.h>
#include <gtkmm/menu.h>
#include <gtkmm/adjustment.h>

namespace froppieLand{
    namespace vue{

        class FroppieVue;

        class ResolutionFL: public Gtk::Frame{
        
        public:
            ResolutionFL(FroppieVue& vue, Glib::ustring titre, const unsigned int resoMin, const unsigned int resoMax);

            ResolutionFL(FroppieVue& vue, Glib::ustring titre);

            ResolutionFL(const ResolutionFL&) = delete;

            ResolutionFL& operator=(const ResolutionFL&) = delete;

        protected:

            void nouvelleResolution();   //méthode sur le signal_selection_done



        protected:

            FroppieVue* _vue;

            Gtk::Menu _menuResolution;

            const unsigned int resoMin, resoMax;

        };
    }
}

#endif