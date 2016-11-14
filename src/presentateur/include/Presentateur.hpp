#ifndef PRESENTATEUR_HPP
#define PRESENTATEUR_HPP

#include <memory>

#include "Grill.hpp"
#include "Froppie.hpp"
#include "Position.hpp"
#include "Direction.hpp"
#include "Nord.hpp"
#include "Sud.hpp"
#include "Est.hpp"
#include "Ouest.hpp"
#include "Self.hpp"

#include "FroppieVue.hpp"

namespace froppieLand{
    namespace presentateur{
        /**
         * Classe Presentateur, faisant la liaison entre la vue et le modele
         */

        class Presentateur{
        
        public:

            typedef modele::Position Position;

            typedef modele::Direction Direction;
            typedef modele::Nord Nord;
            typedef modele::Sud Sud;
            typedef modele::Ouest Ouest;
            typedef modele::Est Est;
            typedef modele::Self Self;
            
            typedef modele::Grill Grill;
            typedef modele::froppie::Froppie Froppie;

            typedef vue::FroppieVue FroppieVue;


        public:

            /**
             * Constructeur du presentateur
             * @param taille la taille de la grille à creer
             * @param ligneDep le numero de ligne où commence Froppie
             * @param colonneDep le numero de colonne où commence Froppie
             * @param ligneArr le numero de ligne où se trouve l'arrivée
             * @param colonneArr le numero de colonne où se trouve l'arrivée
             * @param resoMin la resolution minimale possible pour la grille
             * @param resoMax la resolution maximale possible pour la grille
             * @param tempsPartie le temps maximal d'une partie
             * @param tempsVieillissement le temps d'un tic de veillissement des nenuphars, après cette duree, les nenuphars sur la grille vieillissent d'un cran
             */
            Presentateur(unsigned int taille
            , unsigned int ligneDep, unsigned int colonneDep
            , unsigned int ligneArr, unsigned int colonneArr
            , unsigned int resoMin, unsigned int resoMax
            , unsigned int tempsPartie, unsigned int tempsVieillissement);

        public:

            /**
             * Getter sur le temps maximal de la partie
             */
            const unsigned int& getTempsPartie()const;

            /**
             * Getter sur la duree de chaque phase de viellissement des nenuphars
             */
            const unsigned int& getTempsVieillissement()const;

            /**
             * Getter sur la resolution minimale
             */
            const unsigned int& getResolutionMin()const;

            /**
             * Getter sur la resolution maximale
             */
            const unsigned int& getResolutionMax()const;

            /**
             * Getter sur la dimension de la grille
             */
            const unsigned int& getDimension()const;

            /**
             * Getter sur les points de vie restant de froppie
             */
            const int& getVieFroppie()const;

            /**
             * Getter sur la vue
             */
            FroppieVue* getVue();

            /**
             * Getter sur le type de nenuphar present à la position donnee
             * @param ligne la ligne de la case a tester
             * @param colonne la colonne de la case a tester
             * @return le type du nenuphar en chaines de caracteres, "Eau" si il n'y a pas de nenuphar
             */
            std::string getTypeNenu(const unsigned int& ligne, const unsigned int& colonne)const;

            /**
             * Getter sur l'etat de vie du nenuphar present à la position donnee
             * @param ligne la ligne de la case a tester
             * @param colonne la colonne de la case a tester
             * @return l'etat du nenuphar en chaines de caracteres, "Mort" si il n'y a pas de nenuphar
             */
            std::string getEtatNenu(const unsigned int& ligne, const unsigned int& colonne)const;
            
            /**
             * renvoit l'etat de sante de froppie
             * @return l'etat de froppie en chaines de caracteresn "Sain" si froppie est en bon etat
             */
            std::string getEtatFroppie()const;
 
            /**
             * Lance une nouvelle partie
             * @param resolution la resolution de la grille
             */
            void nouveauJeu(unsigned int resolution);

        public:

            /**
             * lance l'application graphique GTK
             */
            void demarer();

            /**
             * genere les nenuphars sur le terrain
             */
            void genererTerrain();

            /**
             * teste la position donnee est bien sur la position d'arrivee
             * @param ligne la ligne de la case a tester
             * @param colonne la colonne de la case a tester
             * @return True la position donnee est la position d'arrivee, False sinon
             */
            bool isArrived(const unsigned int& ligne, const unsigned int& colonne)const;
            
            /**
             * teste si la position donnee est la case ou se trouve froppie
             * @param ligne la ligne de la case a tester
             * @param colonne la colonne de la case a tester
             * @return True la position donnee est la position de froppie, False sinon
             */
            bool isFroppied(const unsigned int& ligne, const unsigned int& colonne)const;

            /**
             * teste si froppie est encore vivante
             * @return True si l'etat de froppie est autre chose que mort, False sinon
             */
            bool isFroppieVivante()const;

            /**
             * deplace froppie dans la direction donnee
             * @param directionDep la direction dans laquelle froppie doit se deplacer
             * @return True si la partie est terminee, et que froppie est arrivee sur le nenuphar d'arrivee, False sinon
             */
            bool deplaceFroppie(const Direction& directionDep);

            /**
             * fait veillir tous les nenuphars de la grille
             */
            void vieillirCases();

            /**
             * Definie les cases sur lequel il est possible de cliquer pour deplacer froppie
             */
            void setCaseMouvementPoss();
            

        protected:

            /**
             * les resolutions minimales et maximales possibles pour la grille
             */
            const unsigned int _resoMin, _resoMax;

            /**
             * le temps maximal de la partie, et le temps necessaire pour que les nenuphars viellissent d'un cran
             */
            unsigned int _tempsPartie, _tempsVieillissement;

            /**
             * la grille contenant tout le modele de l'application
             */
            std::unique_ptr < Grill > _modele;

            /**
             * contient toute la vue de l'application
             */
            std::unique_ptr < FroppieVue > _vue;
                    
            

            

        };
    }
}

#endif
