#ifndef FROPPIEMOVEOBS_HPP
#define FROPPIEMOVEOBS_HPP

namespace froppieLand{
    namespace modele{

        class FroppieMoveObserver{

        public:
            virtual void notifyMove()const= 0;

        };
    }
}

#endif