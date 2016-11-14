#ifndef FROPPIE_VUE_HPP
#define FROPPIE_VUE_HPP

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/box.h>
#include <gtkmm/stock.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/cellrendererpixbuf.h>

#include <map>

#include "FroppHealth.hpp"
#include "BarreChrono.hpp"
#include "ResolutionFL.hpp"
#include "GGrill.hpp"

namespace froppieLand{

    namespace presentateur{
        class Presentateur;
    }

    namespace modele{
        class Direction;
    }

    namespace vue{

        /**
         * Classe FroppieVue, represente la vue principale
         */
        class FroppieVue: public Gtk::Window{
        public:

            friend class FroppHealth;
            friend class GGrill;
            friend class ResolutionFL;
            friend class BarreChrono;
            friend class GCaseMare;

        public:

            /**
             * Constructeur de froppieVue
             * @param presentateur le presentateur auquel froppieVue doit etre lie
             */
            FroppieVue(presentateur::Presentateur&);

            FroppieVue(const FroppieVue&) = delete;

            FroppieVue& operator=(const FroppieVue&) = delete;

            /**
             * charge l'ensemble des images utilisees par la vue
             */
            static void initialiser();

        public:

            /**
             * affiche les points de vie de froppie dans la fenetre
             */
            void afficherPdvFroppie();

            /**
             * affiche la fenetre de fin de partie
             * @param resultat True si froppie a gagne, False sinon
             */
            void finPartie(bool resultat);
            
            /**
             * desactive toute action de mouvement possible pour froppie
             */
            void casesParDefaut();

            /**
             * active les cases sur lequel froppie peut se deplacer
             * @param ligne la ligne de la case autour duquel froppie peut se deplacer (la case sur lequel se trouve froppie)
             * @param colonne la ligne de la case autour duquel froppie peut se deplacer (la case sur lequel se trouve froppie)
             * @param direction 
             */
            void setCaseMouvable(const unsigned int& ligne, const unsigned int& colonne, GCaseMare::Direction const*);

        public:

            /**
             * Getter sur le presentateur lie a froppieVue
             * @return le presentateur
             */
            const presentateur::Presentateur& getPresentateur()const;

            /**
             * Getter sur le presentateurn modifiable, lie a froppieVue
             * @return le presentateur, modifiable
             */
            presentateur::Presentateur& getModifPresentateur();

            /**
             * renvoit le nom de l'application, "Fr0ppieLand"
             * @return le nom de l'application en chaine de caracteres, "Fr0ppieLand"
             */
            static const Glib::ustring getNomVue();

            /**
             * renvoit la chaine de caracteres "Points de vie :"
             * @return la chaine de caracteres "Points de vie :"
             */
            static const Glib::ustring getNomPdvFroppie();

            /**
             * renvoit la chaine de caracteres "Resolution de la mare :"
             * @return la chaine de caracteres "Resolution de la mare :"
             */
            static const Glib::ustring getNomResolution();

            /**
             * renvoit la chaine de caracteres "Durée de vie des nénuphars"
             * @return la chaine de caracteres "Durée de vie des nénuphars"
             */
            static const Glib::ustring getNomBarreChrono();

            /**
             * renvoit le path contenant les images utilisees par l'application
             * @return la chaine de caracteres du chemin
             */
            static const Glib::ustring getCheminImages();

        protected:

            /**
             * renvoit l'image correspondant au nom donne
             * @param le nom de l'image a recuperer
             */
            static const Glib::RefPtr< Gdk::Pixbuf >& getImage(const Glib::ustring& nom);

            /**
             * fait viellir les cases du plateau et met à jour jour le plateau puis l'affichage
             */
            void leTempsPasse();

        protected:

            /**
             * ouvre la fenetre de presentation de l'application
             */
            void cbPresentation();

            /**
             * ferme l'appplication
             */
            void cbQuitter();

            /**
             * lance la partie
             */
            void cbLancement();

            /**
             * prepare la grille pour la nouvelle partie
             */
            void cbPreparation();

            /**
             * genere la barre d'outils de la fenetre, contenant les boutons controlant l'application
             */
            void buildBarreOutils(Gtk::Box& manager);

            /**
             * genere la partie de la fenetre affichant la grille de jeu
             */
            void buildPartieMillieu(Gtk::Box& manager);

            /**
             * genere la partie de la fenetre affichant le temps restant avant de perdre la partie
             */
            void buildPartieInferieur(Gtk::Box& manager);

        private:

            static std::map < Glib::ustring, Glib::RefPtr < Gdk::Pixbuf > > _images;

            static const Glib::ustring _nomVue;

            static const Glib::ustring _nomPdvFroppie;

            static const Glib::ustring _nomResolution;

            static const Glib::ustring _nomBarreChrono;

            static const Glib::ustring _cheminImages;

        protected:

            presentateur::Presentateur& _presentateur;

            std::unique_ptr< GGrill > _ptrGrillGraphic;

            FroppHealth _pdvFroppie;

            ResolutionFL _resoTerrain;

            BarreChrono _chronometre;

            Gtk::Box _centManager;

            Gtk::Box _infManager;
        };
    }
}

#endif
