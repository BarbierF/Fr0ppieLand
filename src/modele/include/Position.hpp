#ifndef POSITION_HPP
#define POSITION_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        class Position{

            public:

                Position(unsigned int& ligne, unsigned int& colonne);
                Position(const unsigned int& ligne, const unsigned int& colonne);

                const unsigned int& getLigne()const;
                const unsigned int& getColonne()const;

            public:

                void changeValue(const Direction& );

            protected:

                unsigned int _ligne;
                unsigned int _colonne;
        };
    }
}

#endif