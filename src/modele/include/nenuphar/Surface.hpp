#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "surfEtat/SurfEtat.hpp"
#include "strategy/StrategyNenuphar.hpp"
#include "froppie/fropEtat/FropEtat.hpp"
#include "surfEtat/Petit.hpp"
#include "surfEtat/Moyen.hpp"
#include "surfEtat/Grand.hpp"
#include "surfEtat/Inexistant.hpp"
#include "strategy/NenuVieillissant.hpp"
#include "strategy/NenuNonVieillissant.hpp"
#include "strategy/FactoryStrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{

        namespace nenuphar{
            class Froppie;
            class Surface{
            public:

                typedef FactoryStrategyNenuphar::TypeNenu TypeNenu;

                Surface(SurfEtat const* surfEtat, StrategyNenuphar const* strategyNenuphar, unsigned int iS, unsigned int jS);
                Surface(unsigned int iS, unsigned int jS);
                const SurfEtat& getEtat()const;
                void setStrategy(StrategyNenuphar const* strategyNenuphar);
                const StrategyNenuphar& getStrategy()const;
                void age(); //fait viellir le nenuphar
                void generateNenuphar(StrategyNenuphar const* strategyNenuphar); // genère un nénuphar (etat passe à Grand) et assigne la strategie passée en paramètre
                void souffrir(froppie::Froppie& victim)const;
                const unsigned int& getLigne()const;
                const unsigned int& getColonne()const;


            private:
                void vieillirEtat();
                void setEtat(SurfEtat const* nEtat);

                friend void Petit::age(Surface& victim)const;
                friend void Moyen::age(Surface& victim)const;
                friend void Grand::age(Surface& victim)const;
                friend void Inexistant::age(Surface& victim)const;

                friend void NenuVieillissant::vieillir(Surface& victim)const;
                friend void NenuNonVieillissant::vieillir(Surface& victim)const;
                
            private:
                SurfEtat const* _etat;
                StrategyNenuphar const* _strategy;
                const Position _sPosition;
            };
        }
    }
}

#endif /* SURFACE_HPP */