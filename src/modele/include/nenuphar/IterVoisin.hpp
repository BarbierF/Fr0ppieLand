#ifndef ITER_VOISIN_HPP
#define ITER_VOISIN_HPP

#include "../Position.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{

            class IterVoisin{
    
            public:

                IterVoisin(const Position& );

                const Direction& getDirectionActuelle()const;

                void setVoisinPotentiel(const Position& );

            public:

                bool voisinSuivant();

                bool isFini();

                void reset();

            protected:

                const Position _surfPos;

                Position const* _voisinPotentiel;

                unsigned int _currentIndex;

                static const std::vector < Direction > _directions;
            };
        }
    }
}

#endif