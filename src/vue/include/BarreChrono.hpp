#ifndef BARRE_CHRONO_HPP
#define BARRE_CHRONO_HPP

#include <memory>

#include <gtkmm/progressbar.h>
#include <gtkmm/adjustment.h>
#include <glibmm/threads.h>


//
namespace froppieLand{
    namespace modele{

        class BarreChrono: public Gtk::Frame{
        public:
            class FroppieVue;
            class Presentateur;

        public:

            BarreChrono(FroppieVue& vue, Glib::ustring titre);

            void stopChrono();

            const unsigned int& getTempsChrono()const;

            const unsigned int& getTempsVieillissement()const;

        protected:

            void timesUp(Presentateur&);

            void traitementChronoThread();

            void progression();

        protected:

            FroppieVue* _vue

            Gtk::ProgressBar _barProgression;

            bool _enCours;

            std::unique_ptr < Glib::Thread* > _chronoThread;

            static unsigned int _tempsChrono;

            static unsigned int _tempsVieillisement;

        }
    }
}

#endif