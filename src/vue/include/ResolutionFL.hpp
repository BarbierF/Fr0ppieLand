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

        /**
         * la classe gerant la resolution de la grille, le nombre de cases que celle-ci peut contenir
         */
        class ResolutionFL: public Gtk::Frame{
        
        public:
        

            /**
             * Constructeur de ResolutionFL
             * @param vue Le conteneur parent (FroppieVue)
             * @param titre le titre de cette partie de la fenetre
             * @param resoMin la taille minimale de la grille
             * @param resoMax la taille maximale de la grille
             * @param resoCourant la taille actuelle de la grille
             */
            ResolutionFL(FroppieVue& vue, Glib::ustring titre
                , const unsigned int& resoMin
                , const unsigned int& resoMax
                , const unsigned int& resoCourant);

            ResolutionFL(const ResolutionFL&) = delete;

            ResolutionFL& operator=(const ResolutionFL&) = delete;

            /**
            * Getter sur la resolution courante
            * @return la resolution courante
            */
            const unsigned int getResolution()const;

        protected:

            /**
             * prepare la grille pour la nouvelle resolution
             */
            void cbNouvelleResolution();   //méthode sur le signal_selection_done

        protected:

            /**
             * les resolution minimale que peut prendre la grille
             */
            unsigned int _resoMin;
            /**
             * les resolution maximale que peut prendre la grille
             */
            unsigned int _resoMax;
        
            /**
             * la vue liant ResolutionFL au reste des elements de la vue
             */
            FroppieVue* _vue;

            /**
             * les boutons permetant de regler la resolution
             */
            Gtk::SpinButton _sButtons;

            /**
             * la boite englobant les boutons controlant la resolution
             */
            Gtk::Box _manager;

        };
    }
}

#endif
