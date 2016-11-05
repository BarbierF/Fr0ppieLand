#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include "Position.hpp"
#include "Direction.hpp"
#include "Eau.hpp"
#include "Dopant.hpp"
#include "Mortel.hpp"
#include "Nutritif.hpp"
#include "Veneneux.hpp"

    namespace froppieLand{
        namespace modele{
            namespace froppie{
                
                class FropEtat;

                class Froppie{

                public: 

                    friend class Malade;
                    friend class Sain;
                    friend class Mort;

                    friend class nenuphar::Dopant;
                    friend class nenuphar::Eau;
                    friend class nenuphar::Mortel;
                    friend class nenuphar::Nutritif;
                    friend class nenuphar::Veneneux;
                    
                    typedef modele::Direction Direction;

                public: 
                    Froppie(const int pdv, const unsigned int Xdep, const unsigned int Ydep);
                    
                    ~Froppie();

                    Froppie(const Froppie& ) = delete;

                    Froppie& operator=(const Froppie& )const = delete; 

                public:

                    const int& getPDV()const;

                    const unsigned int& getNbMove()const;

                    const Position& getPosition()const;

                    const FropEtat& getEtat()const;

                protected:

                    void setSain();

                    void setMalade();

                    void setMort();

                public:

                    void deplacer(const Direction&);                    

                protected:

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
