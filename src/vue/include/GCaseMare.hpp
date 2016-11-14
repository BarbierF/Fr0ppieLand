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
            /**
             * Typedef de modele::Direction vers Direction
             */
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
             * @return True
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
             * permet une case graphique de faire bouger froppie au clique
             */
            void setMouvement(Direction const*);

        protected:

            /**
             * la grille de jeu graphique
             */
            GGrill& _gGrill;

            /**
             * le numero de ligne de la case
             */
            unsigned int _ligne;
            /**
             * le numero de colonne de la case
             */
            unsigned int _colonne;

            /**
             * la direction vers laquelle froppie se deplace lors du clique sur cette case
             */
            Direction const* _directionClick;

            /**
               la connection necessaire pour gerer l'evenement du clique
            */
            sigc::connection* _connexion;

            //choix du shared_ptr pour pouvoir mettre mettre deux fois la même image dans les maps, ex dopant et mortel
            /**
             * une map des images representant les nenuphars
             */
            std::map < Glib::ustring, std::map < Glib::ustring, std::shared_ptr< Gtk::Image > > > _formes;

            /**
             * une map des images representant froppie
             */
            std::map< std::string, std::unique_ptr< Gtk::Image > > _froppieFormes; 


        };

    }
}

#endif
