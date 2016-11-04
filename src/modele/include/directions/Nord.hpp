#ifndef NORD_HPP
#define NORD_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        class Nord: public Direction{

        public:
            static const Nord& getNord();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            Nord(const Nord& ) = delete;
            Nord& operator=(const Nord& ) = delete;

        private:
            Nord();

            static const Nord _nord;
        };
    }
}

#endif