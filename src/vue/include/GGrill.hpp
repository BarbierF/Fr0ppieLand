#ifndef GRAPHIC_GRILL_HPP
#define GRAPHIC_GRILL_HPP

#include <vector>

#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>

#include "GCaseMare.hpp"

namespace froppieLand{
    namespace vue{

        class FroppieVue;

        class GGrill :public Gtk::AspectFrame{
            
        public:
            friend class GCaseMare;
            friend class FroppieVue;

        public:
            GGrill(FroppieVue& vue);

            GGrill(const GGrill& ) = delete;

            GGrill& operator=(const GGrill& ) = delete;

        public:

            const FroppieVue& getVue()const;

        protected:

            void actualiserCases();            

            void vieillirCases();

            FroppieVue& getModifVue();

        protected:
            
            FroppieVue& _vue;

            Gtk::Grid _mareManager;
        
            std::vector < GCaseMare* > _mare;
        };
    }
}

#endif