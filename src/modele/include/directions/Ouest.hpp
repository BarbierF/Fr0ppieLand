#ifndef SUD_HPP
#define SUD_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        class Ouest: public Direction{

        public:

            static const Ouest& getOuest();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

        private:
            Ouest();

            static const Ouest _ouest;
        };
    }
}

#endif