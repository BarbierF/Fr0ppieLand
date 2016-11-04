#ifndef EST_HPP
#define EST_HPP

#include "Direction.hpp"

namespace froppieLand{
    namespace modele{

        class Est: public Direction{

        public:
            static const Est& getEst();
            const int getVectorXDirection()const override;
            const int getVectorYDirection()const override;

            Est(const Est& ) = delete;
            Est& operator=(const Est& ) = delete;

        private:
            Est();

            static const Est _est;
        };
    }
}
#endif