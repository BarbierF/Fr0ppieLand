#ifndef GRAPHIC_CASE_MARE_HPP
#define GRAPHIC_CASE_MARE_HPP

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>

#include <map>
#include <string>
#include <memory>

#include "Direction.hpp"


namespace froppieLand{

    namespace presentateur{
        class Presentateur;
    };

    namespace vue{

        class GGrill;

        /**
         * Classe GCaseMare, gere les cases de la grille
         */
        class GCaseMare: public Gtk::EventBox{

        public:

            friend class GGrill;
            typedef modele::Direction Direction;

        public:
            
            /**
             * Constructeur de GCaseMare
             * @param ggrill la grille graphique contenant les GCaseMare
             * @param ligne le numero de ligne de cette case
             * @param colonne le numero de colonne de cette case
             */
            GCaseMare(GGrill& ggrill, unsigned int& ligne, unsigned int& colonne);

            /**
             * le destructeur de GCaseMare
             */
            ~GCaseMare();

            /**
             * Getter sur la ligne de la case
             * @return le numero de ligne
            */
            const unsigned int& getLigne()const;

            /**
             * Getter sur la colonne de la case
             * @return le numero de colonne
             */
            const unsigned int& getColonne()const;

            /**
             * Getter sur la grille contenant la case
             * @return la grille grapgique contenant la case
             */
            const GGrill& getGGrill()const;

        protected:

            /**
             * deplace froppie sur la case si possible
             * @return True si froppie a pu etre deplace, False sinon
             */
            bool cbClickSouris(GdkEventButton* evt);

            /**
             * Met a jour l'image de la case
             * @param presentateur le presentateur liant avec le modele
             */
            void majCase(presentateur::Presentateur& );

            /**
             * le comportement par defaut lors d'un clique sur une case
             */
            void defaultClickHandler();

            /**
             *
             */
            void setMouvement(Direction const*);

        protected:

            GGrill& _gGrill;

            unsigned int _ligne, _colonne;

            Direction const* _directionClick;

            sigc::connection* _connexion;

            //choix du shared_ptr pour pouvoir mettre mettre deux fois la même image dans les maps, ex dopant et mortel
            std::map < Glib::ustring, std::map < Glib::ustring, std::shared_ptr< Gtk::Image > > > _formes;

            std::map< std::string, std::unique_ptr< Gtk::Image > > _froppieFormes; 


        };

    }
}

#endif
