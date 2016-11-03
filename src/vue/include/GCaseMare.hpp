#ifndef GRAPHIC_CASE_MARE_HPP
#define GRAPHIC_CASE_MARE_HPP

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>

#include <map>
#include <string>
#include <memory>

#include "../presentateur/Presentateur.hpp"

namespace froppieLand{
    namespace vue{

        class GGrill;

        class GCasesMare: public EventBox{

        public:
            
            GCasesMare(GGrill& ggrill, unsigned int ligne, unsigned int colonne, bool froppiePresente);

            const unsigned int& getLigne()const;

            const unsigned int& getColonne()const;

            const GGrill& getGGrill()const;

        protected:

            bool cbClickSouris(GdkEventButton* evt);

            void majSurface(const Presentateur& );

            void vieillirCase(Presentateur& );

            void actualiserDeplacement(Presentateur& );

        protected:

            unsigned int _ligne;
            
            unsigned int _colonne;

            const GGrill _gGrill;

            bool _froppiePresente;

            Presentateur::Direction const* _directionClick;

            //choix du shared_ptr pour pouvoir mettre mettre deux fois la même image dans les maps, ex dopant et mortel
            std::map < std::string, std::map < std::string, std::shared_ptr< Gtk::image > > > _formes;

            std::map< std::string, std::unique_ptr< Gtk::image > > _froppieForme; 
        };

    }
}

#endif