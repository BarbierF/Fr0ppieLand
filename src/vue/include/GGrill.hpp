#ifndef GRAPHIC_GRILL_HPP
#define GRAPHIC_GRILL_HPP

#include <vector>

#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>

#include "GCaseMare.hpp"

namespace froppieLand{
    namespace vue{

        class FroppieVue;

        /**
         * La classe gerant l'affichage de la grille dans la fenetre
         */
        class GGrill :public Gtk::AspectFrame{
            
        public:
            friend class GCaseMare;
            friend class FroppieVue;

        public:
            /**
             * constructeur de GGrill
             * @param vue la vue principale regroupant les differentes classes
             */
            GGrill(FroppieVue& vue);

            GGrill(const GGrill& ) = delete;

            GGrill& operator=(const GGrill& ) = delete;

        public:

            /**
             * Getter sur la vue principale
             */
            const FroppieVue& getVue()const;

        protected:

            /**
             * Met a jour les cases de la grille en fonction du modele
             */
            void actualiserCases();

            /**
             * Getter sur la vue principale, modifiable
             */
            FroppieVue& getModifVue();

            /**
             * desactive la possible de deplacer froppie en cliquant sur une case
             */
            void disableMove();

            /**
             * active la case pour qu'il soit possible de deplacer froppie dessus
             * @param ligne la ligne de la case
             * @param colonne la colonne de la case
             * @param direction 
             */
            void setCaseMouvable(const unsigned int& ligne, const unsigned int& colonne, GCaseMare::Direction const*);

        protected:
            
            /**
             * la vue liant GGrill au reste des elements de la vue
             */
            FroppieVue& _vue;

            /**
             * Manager de la partie d'affichage de la mare
             */
            Gtk::Grid _mareManager;
        
            /**
             * l'ensemble de cases grahiques representant chaque case de la grille
             */
            std::vector < GCaseMare* > _mare;
        };
    }
}

#endif
