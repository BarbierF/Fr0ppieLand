#ifndef ITER_VOISIN_HPP
#define ITER_VOISIN_HPP

#include <vector>
#include <memory>

#include "Position.hpp"


namespace froppieLand{
    namespace modele{
        class Direction;

        namespace nenuphar{

            class IterVoisin{
    
            public:

                IterVoisin(const Position& positionTest);

                Direction const* getDirectionActuelle()const;

                void setVoisinPotentiel(unsigned int& ligne, unsigned int& colonne );

            public:

                bool voisinSuivant();

                bool isFini()const;

            protected:

                const Position _surfPos;

                std::shared_ptr < const Position > _voisinPotentiel;

                unsigned int _currentIndex;

                static const std::vector < modele::Direction const* > _directions;

                modele::Direction const*  _directionActuelle;
            };
        }
    }
}

#endif