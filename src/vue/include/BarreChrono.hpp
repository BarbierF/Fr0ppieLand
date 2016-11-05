#ifndef BARRE_CHRONO_HPP
#define BARRE_CHRONO_HPP

#include <memory>
#include <thread>

#include <gtkmm/frame.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/adjustment.h>



//
namespace froppieLand{

    namespace presentateur{
        class Presentateur;
    };

    namespace vue{

        class FroppieVue;

        class BarreChrono: public Gtk::Frame{
        public:
            friend class FroppieVue;

        public:

            BarreChrono(FroppieVue& vue, Glib::ustring titre
                , const unsigned int& tempsChrono
                , const unsigned int& tempsVieillissment);

            BarreChrono(const BarreChrono& ) = delete;

            BarreChrono& operator=(const BarreChrono& ) = delete;

            void stopChrono();

            void startChrono();

            const unsigned int& getTempsChrono()const;

            const unsigned int& getTempsVieillissement()const;

        protected:

            void timesUp();

            void traitementChronoThread();

            void progression();

        protected:

            FroppieVue& _vue;

            Gtk::ProgressBar _barProgression;

            bool _enCours;

            std::unique_ptr < std::thread > _chronoThread;

            const unsigned int _tempsChrono;

            const unsigned int _tempsVieillissement;

        };
    }
}

#endif