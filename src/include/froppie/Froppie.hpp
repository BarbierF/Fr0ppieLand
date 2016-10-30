#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include "../Position.hpp"
#include "../directions/Direction.hpp"

    namespace froppieLand{
        namespace modele{
            namespace froppie{
                
                class Direction;
                class FropEtat;

                class Froppie{

                    friend class Malade;
                    friend class Sain;
                    friend class Mort;
                    
                private: 
                    int _pointDeVie;
                    unsigned int _nbMove;
                    Position _position;

                    const FropEtat* _etat;

                    void setEtat(const FropEtat&);

                public: 
                    Froppie(const int& pdv, const unsigned int& Xdep, const unsigned int& Ydep);
                    ~Froppie();

                    bool deplacer(const Direction&, const unsigned int& tailleEnv);
                    const Position& getPosition()const;

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
    }

#endif
