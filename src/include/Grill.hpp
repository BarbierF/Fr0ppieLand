#ifndef GRILL_HPP
#define GRILL_HPP

#include <vector>

#include "Position.hpp"
#include "FroppieMoveObserver.hpp"
#include "NonCopyable.hpp"
#include "Surface.hpp"
#include "Froppie.hpp"

namespace froppieLand{
    namespace modele{

        class Grill: public FroppieMoveObserver, public NonCopyable{
        private:
            const Position _depart;
            const Position _arrivee;

            unsigned int _taille;

            std::vector< Surface* > _terrain;
            Froppie* _froppie;
        public:
            
            Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA);
            ~Grill();

            const unsigned int& getTaille(void)const;
            const Position& getDepart(void)const;
            const Position& getArrivee(void)const;
            Froppie& getFroppie(void)const;
            const Surface& getCase(unsigned int X, unsigned int Y)const;

            void consChemin(void) const;
            void vieilissement();
            
            void notifyMove()const;
        };
    }
}

#endif