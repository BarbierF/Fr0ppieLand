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
            
            Grill(
                unsigned int taille
                , unsigned int posLigneD
                , unsigned int posColonneD
                , unsigned int posLigneA
                , unsigned int posColonneA
            );

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

            Surface& getModifFroppieSurf();

        public:

            void construireChemin(void);

            void vieillissement();

            void deplacerFroppie(const Direction& );

        protected:

            void adapterSurface(const unsigned int& ligne, const unsigned int& colonne);

        protected:

            Froppie _froppie;

            unsigned int _taille;

            const Position _depart, _arrivee;

            std::vector< Surface > _terrain;

        };
    }
}

#endif