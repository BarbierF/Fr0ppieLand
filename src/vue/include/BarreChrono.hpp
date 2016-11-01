#ifndef BARRE_CHRONO_HPP
#define BARRE_CHRONO_HPP

#include <gtkmm/progressbar.h>
#include <gtkmm/adjustment.h>
#include <glibmm/threads.h>


//
namespace froppieLand{
    namespace modele{

        class BarreChrono: public Gtk::Frame{
        public:
            
            class Presentateur;

        public:

        
        protected:

            void timesUp(Presentateur&);

        protected:

            Gtk::ProgressBar _progressBar;

        }
    }
}

#endif