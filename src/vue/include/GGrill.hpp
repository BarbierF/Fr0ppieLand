#ifndef GRAPHIC_GRILL_HPP
#define GRAPHIC_GRILL_HPP

#include <vector>

#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>

#include "include/GCaseMare.hpp"

namespace froppieLand{
    namespace vue{

        class GGrill :public AspectFrame{
            
        public:
            friend class GCaseMare;
            friend class FroppieVue;

        public:
            GGrill(FroppieVue& vue);

        public:

            const FroppieVue& getVue()const;

        protected:
        
            FroppieVue& getModifVue();

            void majVieillissementCases(const Presentateur&);

        protected:

            Gtk::Grid _mareManager;
            
            FroppieVue& _vue;
        
            std::vector < GCaseMare > _mare;
        };
    }
}

#endif