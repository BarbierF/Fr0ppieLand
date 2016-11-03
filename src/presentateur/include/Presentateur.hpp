#ifndef PRESENTATEUR_HPP
#define PRESENTATEUR_HPP

#include <memory>

#include "../modele/include/Grill.hpp"
#include "../modele/include/directions/Direction.hpp"
#include "../modele/include/directions/Nord.hpp"
#include "../modele/include/directions/Sud.hpp"
#include "../modele/include/directions/Est.hpp"
#include "../modele/include/directions/Ouest.hpp"
#include "../modele/include/directions/Self.hpp"

namespace froppieLand{
    namespace presentateur{

        class Presentateur{
        
        public:

            typedef modele::Direction Direction;
            typedef modele::Nord Nord;
            typedef modele::Sud Sud;
            typedef modele::Ouest Ouest;
            typedef modele::Est Est;
            typedef modele::Self Self;
            



        public:

            Presentateur(FroppieVue& , Grill&
            , const unsigned int taille
            , const unsigned int depX, const unsigned int depY
            , const unsigned int arrX, const unsigned int arrY
            , const unsigned int resoMin, const unsigned int resoMax
            , unsigned int tempsPartie, const unsigned int tempsVieillissement);

        public:

            const unsigned int& getTempsPartie()const;

            const unsigned int& getTempsVieillissement()const;

            const unsigned int& getResolutionMin()const;

            const unsigned int& getResolutionMax()const;

            const int& getVieFroppie()const;

            const Direction& getDerniereDireFroppieVoisin()const;
 
        public:

            bool isPossibleMove(const unsigned int& _ligne, const unsigned int& _colonne);

            bool isArrived(const unsigned int& _ligne, const unsigned int& _colonne)const;
            


        protected:

            const unsigned int _resoMin, _resoMax;

            const unsigned int _tempsPartie, _tempsVieillissement;
                    
            std::unique_ptr < Grill > _modele;

            std::unique_ptr < FroppieVue > _vue;

        };
    }
}

#endif