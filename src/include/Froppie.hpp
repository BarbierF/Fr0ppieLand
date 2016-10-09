#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include <list>
#include "Position.hpp"
#include "FroppieMoveObserver.hpp"
#include "MoveObservable.hpp"

    namespace froppieLand{
        namespace modele{

            class Direction;
            class FropEtat;

            class Froppie: public MoveObservable{

            private: 
                int _pointDeVie;
                unsigned int _nbMove;
                Position _position;

                FropEtat* _etat;

                std::list<FroppieMoveObserver*>* _moveObservers;

            public: 
                Froppie(const int& pdv, const unsigned int& Xdep, const unsigned int& Ydep);
                ~Froppie();

                bool deplacer(const Direction&, const unsigned int& tailleEnv);
                bool subir(const int& degats);
                bool changeEtat();
                const Position& getPosition()const;
                void setPosition(int, int);

                void addMoveObserver(FroppieMoveObserver&);
                void notifyMoveObservers();

                const FropEtat& getCurEtat()const;
                void setEtat(const FropEtat&);

                void reduceHealth();
                void doubleHealth();
                void increaseHealth();


            };
        }
    }

#endif
