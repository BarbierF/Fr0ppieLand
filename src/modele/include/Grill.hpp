#ifndef GRILL_HPP
#define GRILL_HPP

#include <vector>

#include "Position.hpp"
#include "Surface.hpp"
#include "Froppie.hpp"

namespace froppieLand{
    namespace modele{
        /**
         * Classe Grill, contenant tout le jeu
         * Contient la grille de jeu, les nénuphars et Froppie
         */
        class Grill{

        public: 
            typedef froppie::Froppie Froppie;

            typedef nenuphar::Surface Surface;
            
        public:
            /**
             * Constructeur d'une grille selon sa taille et la position de Départ et d'Arrivée
             */
            Grill(
                unsigned int taille
                , unsigned int posLigneD
                , unsigned int posColonneD
                , unsigned int posLigneA
                , unsigned int posColonneA
            );

            /**
             * Suppression du constructeur par recopie
             */
            Grill(const Grill& ) = delete;

            /**
             * Suppression de l'opérateur d'attribution 
             */
            Grill& operator=(const Grill&)const = delete;

        public:
            /**
             * Getter de la taille
             * @return la taille de la grille
             */
            const unsigned int& getTaille(void)const;

            /**
             * Getter de la position de départ
             * @return Position de départ 
             */
            const Position& getDepart(void)const;
            
            /**
             * Getter de la position d'arrivée
             * @return Position d'arrivée
             */
            const Position& getArrivee(void)const;
            
            /**
             * Getter de froppie
             * @return Froppie (const)
             */
            const Froppie& getFroppie(void)const;
            
            /**
             * Getter de froppie en mode non constant
             * @return Froppie
             */
            Froppie& getModifFroppie(void);
            
            /**
             * Getter de la surface à la position renseignée
             * @param ligne Composante X de la position
             * @param colonne Composante Y de la position
             * @return la surface correspondante (const)
             */
            const Surface& getSurface(const unsigned int& ligne, const unsigned int& colonne)const;
            
            /**
             * Getter de la surface à la position renseignée en mode non constant
             * @param ligne Composante X de la position
             * @param colonne Composante Y de la position
             * @return la surface correspondante
             */
            Surface& getSurfaceModifiable(const unsigned int& ligne, const unsigned int& colonne);
            
            /**
             * Getter de la surface à la position de Froppie
             * @param ligne Composante X de la position
             * @param colonne Composante Y de la position
             * @return la surface correspondante (const)
             */
            const Surface& getFroppieSurf()const;
            
            /**
             * Getter de la surface à la position de Froppie en mode non constant
             * @param ligne Composante X de la position
             * @param colonne Composante Y de la position
             * @return la surface correspondante
             */
            Surface& getModifFroppieSurf();

        public:
            
            void construireChemin(void);
            /**
             * Action de vieillissement sur toutes les cases (donc nénuphars) de la grille
             */
            void vieillissement();
            /**
             * Action de déplacement dans un vecteur donné
             * @param le vecteur de translation
             */
            void deplacerFroppie(const Direction& );

        protected:

            void adapterSurface(const unsigned int& ligne, const unsigned int& colonne);

        protected:
            /**
             * Champ de stockage de Froppie
             */
            Froppie _froppie;

            /**
             * Taille de la grille
             */
            unsigned int _taille;
            /**
             *  Positions de départ et d'arrivée
             */
            const Position _depart, _arrivee;

            /**
             * Ensemble des surfaces décrivant le terrain de jeu
             */
            std::vector< Surface > _terrain;

        };
    }
}

#endif