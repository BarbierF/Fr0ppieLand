#ifndef MOVE_OBSERVABLE_HPP
#define MOVE_OBSERVABLE_HPP

namespace froppieLand{
    namespace modele{

        class MoveObservable{

            virtual void addMoveObserver(FroppieMoveObserver*) = 0;
            virtual void notifyMoveObservers()= 0;
        };
    }
}

#endif