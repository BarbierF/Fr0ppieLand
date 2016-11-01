#ifndef PRESENTATEUR_HPP
#define PRESENTATEUR_HPP

#include "../modele/include/directions/Direction.hpp"
#include "../modele/include/directions/Nord.hpp"
#include "../modele/include/directions/Sud.hpp"
#include "../modele/include/directions/Est.hpp"
#include "../modele/include/directions/Ouest.hpp"
#include "../modele/include/directions/Self.hpp"

namespace froppieLand{
    namespace presentateur{

        class Presentateur{
        
        public:

            typedef modele::Direction Direction;
            typedef modele::Nord Nord;
            typedef modele::Sud Sud;
            typedef modele::Ouest Ouest;
            typedef modele::Est Est;
            typedef modele::Self Self;

        

        };
    }
}

#endif