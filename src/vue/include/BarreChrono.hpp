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

        /**
         * Classe BarreChrono, gere la partie de la fenetre contenant le chronometre
         */
        class BarreChrono: public Gtk::Frame{
        public:
            friend class FroppieVue;

        public:

            /**
             * Constructeur de BarreChrono
             * @param vue la vue principale
             * @param titre le titre de cette partie de la fenetre
             * @param tempsChrono la duree maximale d'une partie
             * @param tempsVieillissment le temps entre deux etapes de vieillissement
             */
            BarreChrono(FroppieVue& vue, Glib::ustring titre
                , const unsigned int& tempsChrono
                , const unsigned int& tempsVieillissment);

            BarreChrono& operator=(const BarreChrono& ) = delete;

            /**
             * arrete le chronometre
             */
            void stopChrono();

            /**
             * remet a zero le chronometre
             */
            void resetChrono();

            /**
             * demarre le chronometre
             */
            void startChrono();

        protected:

            /**
             * termine la partie une fois le temps limite atteint
             */
            void timesUp();

            /**
             * augmente le chronometre si le temps limite n'est pas atteint et met a jour la vue
             */
            bool traitementTimer(int t_number);

            /**
             * fait avancer d'une case la barre du chronometre
             */
            void progression();

        protected:

            /**
             * la vue liant BarreChrono au autres elements de la vue
             */
            FroppieVue& _vue;

            /**
             * True si le chronometre doit continuer,
             * False si le temps limite a ete depasse
             */
            bool _enCours;

            unsigned int _secondeTime;

            /**
             * la barre de progression graphique
             */
            Gtk::ProgressBar _barProgression;

            /**
             * le timer utilise pour compter
             */
            sigc::connection _timer;

            /**
             * le temps maximal du chronometre
             */
            const unsigned int _tempsChrono;

            /**
             * le temps entre deux etapes de vieillissement
             */
            const unsigned int _tempsVieillissement;

            /**
             * la fenetre englobant la barre de progression
             */
            Gtk::Box _manager;

        };
    }
}

#endif
