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

        class GCaseMare: public Gtk::EventBox{

        public:

            friend class GGrill;
            typedef modele::Direction Direction;

        public:
            
            GCaseMare(GGrill& ggrill, unsigned int& ligne, unsigned int& colonne);

            const unsigned int& getLigne()const;

            const unsigned int& getColonne()const;

            const GGrill& getGGrill()const;

        protected:

            bool cbClickSouris(GdkEventButton* evt);

            void majCase(presentateur::Presentateur& );

            void defaultClickHandler();

            void setMouvement(Direction const*);

        protected:

            GGrill& _gGrill;

            unsigned int _ligne, _colonne;

            Direction const* _directionClick;

            sigc::connection _connexion;

            //choix du shared_ptr pour pouvoir mettre mettre deux fois la même image dans les maps, ex dopant et mortel
            std::map < Glib::ustring, std::map < Glib::ustring, std::shared_ptr< Gtk::Image > > > _formes;

            std::map< std::string, std::unique_ptr< Gtk::Image > > _froppieFormes; 


        };

    }
}

#endif