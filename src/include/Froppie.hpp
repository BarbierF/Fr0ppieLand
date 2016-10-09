#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include <list>
#include "Position.hpp"
#include "Direction.hpp"
#include "FroppieMoveObserver.hpp"
#include "MoveObservable.hpp"

    namespace froppieLand{
        namespace modele{

            class Direction;
            class FropEtat;

            class Froppie: public MoveObservable{

                friend class Malade;
                friend class Sain;
                friend class Mort;
                
            private: 
                int _pointDeVie;
                unsigned int _nbMove;
                Position _position;

                const FropEtat* _etat;

                std::list<const FroppieMoveObserver*>* _moveObservers;

                void setEtat(const FropEtat&);

            public: 
                Froppie(const int& pdv, const unsigned int& Xdep, const unsigned int& Ydep);
                ~Froppie();

                bool deplacer(const Direction&, const unsigned int& tailleEnv);
                const Position& getPosition()const;

                void addMoveObserver(FroppieMoveObserver*);
                void notifyMoveObservers();

                const FropEtat& getCurEtat()const;
                void setSain();
                void setMalade();
                void setMort();

                void subir();
                void doper();
                void soigner();


            };
        }
    }

#endif
