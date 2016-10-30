#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include "Froppie.hpp"

namespace froppieLand{
    namespace modele{

        class Direction{
        public:
            virtual const int getVectorXDirection()const = 0;
            virtual const int getVectorYDirection()const = 0;
        };
    }
}

#endif