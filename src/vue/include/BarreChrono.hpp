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

            BarreChrono(const BarreChrono& ) = delete;

            BarreChrono& operator=(const BarreChrono& ) = delete;

            void stopChrono();

            void startChrono();

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

            const unsigned int _tempsChrono;

            const unsigned int _tempsVieillisement;

        }
    }
}

#endif