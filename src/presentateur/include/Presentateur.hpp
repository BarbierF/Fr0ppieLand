#ifndef PRESENTATEUR_HPP
#define PRESENTATEUR_HPP

#include <memory>

#include "Grill.hpp"
#include "Froppie.hpp"
#include "Position.hpp"
#include "Direction.hpp"
#include "Nord.hpp"
#include "Sud.hpp"
#include "Est.hpp"
#include "Ouest.hpp"
#include "Self.hpp"

#include "FroppieVue.hpp"

namespace froppieLand{
    namespace presentateur{

        class Presentateur{
        
        public:

            typedef modele::Position Position;

            typedef modele::Direction Direction;
            typedef modele::Nord Nord;
            typedef modele::Sud Sud;
            typedef modele::Ouest Ouest;
            typedef modele::Est Est;
            typedef modele::Self Self;
            
            typedef modele::Grill Grill;
            typedef modele::froppie::Froppie Froppie;

            typedef vue::FroppieVue FroppieVue;


        public:

            Presentateur(unsigned int taille
            , unsigned int depX, unsigned int depY
            , unsigned int arrX, unsigned int arrY
            , unsigned int resoMin, unsigned int resoMax
            , unsigned int tempsPartie, unsigned int tempsVieillissement);

        public:

            const unsigned int& getTempsPartie()const;

            const unsigned int& getTempsVieillissement()const;

            const unsigned int& getResolutionMin()const;

            const unsigned int& getResolutionMax()const;

            const unsigned int& getDimension()const;

            const int& getVieFroppie()const;

            FroppieVue* getVue();

            const Direction& getDerniereDireFroppieVoisin()const;

            std::string getTypeNenu(const unsigned int& ligne, const unsigned int& colonne)const;

            std::string getEtatNenu(const unsigned int& ligne, const unsigned int& colonne)const;
            
            std::string getEtatFroppie()const;
 
            void OMGFroppieIsGettingEaten();

            void nouveauJeu(unsigned int resolution);

        public:

            void demarer();

            bool isPossibleMove(const unsigned int ligne, const unsigned int colonne);

            bool isArrived(const unsigned int& ligne, const unsigned int& colonne)const;
            
            bool isFroppied(const unsigned int& ligne, const unsigned int& colonne)const;

            void deplaceFroppie(const Direction& directionDep);

            void vieillirCase(const unsigned int& ligne, const unsigned int& colonne);



        protected:

            const unsigned int _resoMin, _resoMax;

            unsigned int _tempsPartie, _tempsVieillissement;

            std::unique_ptr < Grill > _modele;

            std::unique_ptr < FroppieVue > _vue;
                    
            

            

        };
    }
}

#endif