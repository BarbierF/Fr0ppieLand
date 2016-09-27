#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include <list>
#include "Position.hpp"
#include "FroppieMoveObserver.hpp"
#include "MoveObservable.hpp"

    namespace froppieLand{
        namespace modele{

            class Direction;

            class Froppie: public MoveObservable{

            private: 
                int _pointDeVie;
                unsigned int _nbMove;
                Position _position; 
                bool _sain;
                bool _mort;
                bool _malade;

                std::list<FroppieMoveObserver*>* _moveObservers;

            public: 
                Froppie(const int& pdv, const unsigned int& Xdep, const unsigned int& Ydep);
                ~Froppie();

                bool deplacer(const Direction&, const unsigned int& tailleEnv);
                bool subir(const int& degats);
                bool changeEtat();
                void souffre(const StrategyNenuphar& nenuphar);
                const Position& getPosition()const;
                void setPosition(int, int);

                void addMoveObserver(FroppieMoveObserver&);
                void notifyMoveObservers();

                const bool& isSain() const;
                const bool& isMort() const;
                const bool& isMalade() const;

                void setSain();
                void setMort();
                void setMalade();


            };
        }
    }

#endif
