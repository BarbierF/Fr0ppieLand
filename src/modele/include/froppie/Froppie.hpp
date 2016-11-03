#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include "../Position.hpp"
#include "../directions/Direction.hpp"

    namespace froppieLand{
        namespace modele{
            namespace froppie{
                
                class FropEtat;

                class Froppie{

                    friend class Malade;
                    friend class Sain;
                    friend class Mort;
                    
                    typedef modele::Direction Direction;

                public: 
                    Froppie(const int& pdv, const unsigned int& Xdep, const unsigned int& Ydep);
                    
                    ~Froppie();

                    Froppie(const Froppie& ) = delete;

                    Froppie& operator=(const Froppie& )const = delete; 

                public:

                    const int& getPDV()const;

                    const unsigned int getNbMove()const;

                    const Position& getPosition()const;

                    const FropEtat& getCurEtat()const;

                protected:

                    void setEtat(FropEtat const*);


                public:

                    bool deplacer(const Direction&, const unsigned int& tailleEnv);

                    void subir();

                    void doper();

                    void soigner();


                protected: 

                    int _pointDeVie;

                    unsigned int _nbMove;

                    Position _position;

                    FropEtat const* _etat;


                };
            }

            
        }
    }

#endif
