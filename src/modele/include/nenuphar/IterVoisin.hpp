#ifndef ITER_VOISIN_HPP
#define ITER_VOISIN_HPP

#include <vector>

#include "../Position.hpp"


namespace froppieLand{
    namespace modele{
        class Direction;

        namespace nenuphar{

            class IterVoisin{
    
            public:

                IterVoisin(const Position& positionTest);

                const Direction& getDirectionActuelle()const;

                void setVoisinPotentiel(const Position& );

            public:

                bool voisinSuivant();

                bool isFini()const;

                void reset();

            protected:

                const Position _surfPos;

                Position const* _voisinPotentiel;

                unsigned int _currentIndex;

                static const std::vector < modele::Direction const* > _directions;
            };
        }
    }
}

#endif