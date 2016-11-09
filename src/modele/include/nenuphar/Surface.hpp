#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <map>

#include "IterVoisin.hpp"
#include "SurfEtat.hpp"
#include "StrategyNenuphar.hpp"
#include "FropEtat.hpp"
#include "Petit.hpp"
#include "Moyen.hpp"
#include "Grand.hpp"
#include "Inexistant.hpp"
#include "NenuVieillissant.hpp"
#include "NenuNonVieillissant.hpp"
#include "FactoryStrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{

        class Grill;

        namespace nenuphar{

            class Froppie;

            class Surface{

            public:

                friend class Grill;

            public:

                typedef FactoryStrategyNenuphar::TypeNenu TypeNenu;

                Surface(SurfEtat const* surfEtat
                , StrategyNenuphar const* strategyNenuphar
                , unsigned int iS
                , unsigned int jS
                , const unsigned int& dimension);
                
                Surface(unsigned int iS, unsigned int jS);
                
                const SurfEtat& getEtat()const;
                
                const unsigned int& getLigne()const;
                
                const unsigned int& getColonne()const;
                
                void setStrategy(StrategyNenuphar const* strategyNenuphar);

            public:
                
                const StrategyNenuphar& getStrategy()const;
                
                void age(); //fait viellir le nenuphar
                
                void generateNenuphar(StrategyNenuphar const* strategyNenuphar); // genère un nénuphar (etat passe à Grand) et assigne la strategie passée en paramètre
                
                void souffrir(froppie::Froppie& victim)const;

                bool isCaseVoisine(const unsigned int& ligne, const unsigned int& colonne);

                Direction const* getDirectionVoisin()const;


            protected:

                void vieillirEtat();

                std::map < Position, Direction const* > genererMapVoisins(const unsigned int& dimension)const;
                
                void setEtat(SurfEtat const* nEtat);

                friend void Petit::age(Surface& victim)const;
                
                friend void Moyen::age(Surface& victim)const;
                
                friend void Grand::age(Surface& victim)const;
                
                friend void Inexistant::age(Surface& victim)const;

                friend void NenuVieillissant::vieillir(Surface& victim)const;
                
                friend void NenuNonVieillissant::vieillir(Surface& victim)const;
                
            protected:

                SurfEtat const* _etat;

                StrategyNenuphar const* _strategy;

                const Position _sPosition;

                IterVoisin _iterVoisin;

                std::map < Position, Direction const* > _voisins;

            };
        }
    }
}

#endif /* SURFACE_HPP */
