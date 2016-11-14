#ifndef FROPP_HEALTH_HPP
#define FROPP_HEALTH_HPP

#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>

#include <memory>


namespace froppieLand{

    namespace presentateur{
        class Presentateur;
    };

    namespace vue{

        class FroppieVue;

        /**
         * La classe gerant l'affichage de la vie de froppie et de son etat de sante
         */
        class FroppHealth: public Gtk::Frame{

        public:

            friend class FroppieVue;

        public:

            /** le constructeur de FroppHealth
             * @param vue la vue principale
             * @param titre le tritre de cette partie de la fenetre
             */
            FroppHealth(FroppieVue& vue, Glib::ustring titre);

            FroppHealth(const FroppHealth&) = delete;

            FroppHealth& operator=(const FroppHealth&) = delete;

            /**
             * Getter sur l'image utilsee pour representer l'etat de sante de froppie de froppie
             * @return l'image representant l'etat
             */
            const Gtk::Image& getImage()const;

        protected:

            /**
             * Setter sur l'image represenant l'etat de sante de froppie
             @param presentateur le presentateur permettant de recuperer les points de vies de froppie
             @param image l'image a utiliser
            */
            void setImage(const presentateur::Presentateur& presentateur, 
                const Glib::ustring& image);

            /**
             * recupere les points de vie de froppie et modifie les points de vie affiche dans la fenetre
             * @param presentateur le presentateur permettant de recuperer les points de vies de froppie
             */
            void majFroppHealth(const presentateur::Presentateur& presentateur);
        
        protected:

            FroppieVue& _vue; 

            std::unique_ptr < Gtk::Image > _coeur;

            Gtk::Label _labelPdv;

            Gtk::HBox _manager;

        };
    }
}

#endif
