#ifndef GRILL_HPP
#define GRILL_HPP

#include <vector>

#include "Position.hpp"
#include "nenuphar/Surface.hpp"
#include "froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{

        class Grill{

        public: 
            typedef froppie::Froppie Froppie;

            typedef nenuphar::Surface Surface;
            
        public:
            
            Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA);
            
            ~Grill();

            Grill(const Grill& ) = delete;

            Grill& operator=(const Grill&)const = delete;

        public:

            const unsigned int& getTaille(void)const;

            const Position& getDepart(void)const;

            const Position& getArrivee(void)const;

            const Froppie& getFroppie(void)const;

            Froppie& getModifFroppie(void);

            const Surface& getCase(const unsigned int& ligne, const unsigned int& colonne)const;

            const Surface& getFroppieSurf()const;

        public:

            void consChemin(void) const;

            void vieilissement();

        protected:

            const Position _depart;

            const Position _arrivee;

            unsigned int _taille;

            std::vector< Surface > _terrain;

            Froppie& _froppie;
        };
    }
}

#endif