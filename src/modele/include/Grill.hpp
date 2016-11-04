#ifndef GRILL_HPP
#define GRILL_HPP

#include <vector>

#include "Position.hpp"
#include "Surface.hpp"
#include "Froppie.hpp"

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

            const Surface& getSurface(const unsigned int& ligne, const unsigned int& colonne)const;

            Surface& getSurfaceModifiable(const unsigned int& ligne, const unsigned int& colonne);
            
            const Surface& getFroppieSurf()const;

        public:

            void construireChemin(void);

            void vieilissement();

        protected:

            const Position _depart, _arrivee;

            unsigned int _taille;

            std::vector< Surface > _terrain;

            Froppie _froppie;
        };
    }
}

#endif