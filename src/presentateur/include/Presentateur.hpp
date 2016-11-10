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
            , unsigned int ligneDep, unsigned int colonneDep
            , unsigned int ligneArr, unsigned int colonneArr
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

            std::string getTypeNenu(const unsigned int& ligne, const unsigned int& colonne)const;

            std::string getEtatNenu(const unsigned int& ligne, const unsigned int& colonne)const;
            
            std::string getEtatFroppie()const;
 
            void OMGFroppieIsGettingEaten();

            void nouveauJeu(unsigned int resolution);

        public:

            void demarer();

            void genererTerrain();

            bool isArrived(const unsigned int& ligne, const unsigned int& colonne)const;
            
            bool isFroppied(const unsigned int& ligne, const unsigned int& colonne)const;

            bool isFroppieVivante()const;
            
            void deplaceFroppie(const Direction& directionDep);

            void vieillirCases();

            void setCaseMouvementPoss();
            

        protected:

            const unsigned int _resoMin, _resoMax;

            unsigned int _tempsPartie, _tempsVieillissement;

            std::unique_ptr < Grill > _modele;

            std::unique_ptr < FroppieVue > _vue;
                    
            

            

        };
    }
}

#endif