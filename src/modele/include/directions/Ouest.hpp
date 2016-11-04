#ifndef OUEST_HPP
#define OUEST_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        class Ouest: public Direction{

        public:

            static const Ouest& getOuest();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            Ouest(const Ouest& ) = delete;
            Ouest& operator=(const Ouest& ) = delete;

        private:
            Ouest();

            static const Ouest _ouest;
        };
    }
}

#endif