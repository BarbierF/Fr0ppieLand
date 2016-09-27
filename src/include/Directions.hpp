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

        class Nord: public Direction{

            const int getVectorXDirection()const;
            const int getVectorYDirection()const;
        };

        class Sud: public Direction{

            const int getVectorXDirection()const;
            const int getVectorYDirection()const;
        };

        class Est: public Direction{

            const int getVectorXDirection()const;
            const int getVectorYDirection()const;
        };

        class Ouest: public Direction{
            
            const int getVectorXDirection()const;
            const int getVectorYDirection()const;
        };
    }
}

#endif