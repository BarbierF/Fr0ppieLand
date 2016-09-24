#ifndef GRILL_HPP
#define GRILL_HPP

namespace froppieLand{
    namespace modele{
        class Surface;
        class Froppie;

        class Grill{

            Grill(const Grille&) = 0;
            Grill& operator=(const Grill&) = 0;
        private:
            const Position _depart;
            const Position _arrivee;

            unsigned int _taille;

            Surface** _terrain;
            Froppie* _froppie;
        public:
            
            Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA);
            ~Grill();

            const Position& getDepart(void)const;
            const Position& getArrivee(void)const;
            Froppie& getFroppie(void)const;
            const Surface& getCase(unsigned int X, unsigned int Y)const;

            void buildChemin(void);
            void vieilissement();
            
            
        };
    }
}

#endif