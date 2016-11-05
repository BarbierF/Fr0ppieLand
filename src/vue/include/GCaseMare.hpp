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
        

        public:
            
            GCaseMare(GGrill& ggrill, unsigned int& ligne, unsigned int& colonne);

            const unsigned int& getLigne()const;

            const unsigned int& getColonne()const;

            const GGrill& getGGrill()const;

        protected:

            bool cbClickSouris(GdkEventButton* evt);

            void majCase(presentateur::Presentateur& );

            void vieillirCase(presentateur::Presentateur& );

        protected:

            unsigned int _ligne, _colonne;

            GGrill& _gGrill;

            modele::Direction const* _directionClick;

            //choix du shared_ptr pour pouvoir mettre mettre deux fois la même image dans les maps, ex dopant et mortel
            std::map < Glib::ustring, std::map < Glib::ustring, std::shared_ptr< Gtk::Image > > > _formes;

            std::map< std::string, std::unique_ptr< Gtk::Image > > _froppieFormes; 
        };

    }
}

#endif