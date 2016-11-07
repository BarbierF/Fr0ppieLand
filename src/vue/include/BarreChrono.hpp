#ifndef BARRE_CHRONO_HPP
#define BARRE_CHRONO_HPP

#include <memory>
#include <thread>

#include <gtkmm/frame.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/box.h>



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

            BarreChrono& operator=(const BarreChrono& ) = delete;

            void stopChrono();

            void resetChrono();

            void startChrono();

            const unsigned int& getTempsChrono()const;

            const unsigned int& getTempsVieillissement()const;

        protected:

            void timesUp();

            bool traitementTimer(int t_number);

            void progression();

        protected:

            FroppieVue& _vue;

            bool _enCours;

            unsigned int _secondeTime;

            Gtk::ProgressBar _barProgression;

            std::unique_ptr < sigc::connection > _timer;

            const unsigned int _tempsChrono;

            const unsigned int _tempsVieillissement;

            Gtk::Box _manager;

        };
    }
}

#endif