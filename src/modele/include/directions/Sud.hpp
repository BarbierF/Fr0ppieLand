#ifndef SUD_HPP
#define SUD_HPP

#include "Direction.hpp"

namespace froppieLand{

    namespace modele{

        class Sud: public Direction{

        public:
            static const Sud& getSud();
            const int getVectorXDirection()const;
            const int getVectorYDirection()const;
        
        private:
            Sud();

            static const Sud _sud;
        };
    }
}
#endif