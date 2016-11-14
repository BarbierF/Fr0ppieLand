#ifndef POSITION_HPP
#define POSITION_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{
        /**
         * Classe décrivant la position d'un élément
         */
        class Position{

            public:
                /**
                 * Constructeur par coordonnées
                 * @param ligne position X
                 * @param colonne position Y
                 */
                Position(unsigned int& ligne, unsigned int& colonne);
                /**
                 * Constructeur par coordonnées constantes
                 * @param ligne position X
                 * @param colonne position Y
                 */
                Position(const unsigned int& ligne, const unsigned int& colonne);

                /**
                 * Getter de la position dans l'axe X (les lignes)
                 */
                const unsigned int& getLigne()const;
                /**
                 * Getter de la position dans l'axe Y (les colonnes)
                 */
                const unsigned int& getColonne()const;

                /**
                 * Fonction de comparaison de positions
                 * @param o position à comparer
                 */
                bool operator<(const Position& o)const;

            public:
                /**
                 * Translation de position selon un vecteur Direction
                 * @param direction Vecteur de translation
                 */
                void changeValue(const Direction& );

            protected:

                /**
                 * Composante X de la position
                 */
                unsigned int _ligne;

                /**
                 * Composante Y de la position
                 */
                unsigned int _colonne;
        };
    }
}

#endif