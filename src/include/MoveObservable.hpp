#ifndef MOVE_OBSERVABLE_HPP
#define MOVE_OBSERVABLE_HPP

namespace froppieLand{
    namespace modele{

        class MoveObservable{

            virtual void addMoveObserver(const FroppieMoveObserver&) = 0;
            virtual void notifyMoveObserver() = 0;
        };
    }
}

#endif