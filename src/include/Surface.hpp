#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "SurfEtat.hpp"
#include "StrategyNenuphar.hpp"
#include "DummyFropEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Froppie;
        class Surface{
        public:
            Surface(SurfEtat& surfEtat, StrategyNenuphar& strategyNenuphar);
            const SurfEtat& getEtat()const;
            void setStrategy(StrategyNenuphar& strategyNenuphar);
            const StrategyNenuphar& getStrategy()const;
            void age(); //fait viellir le nenuphar
            void generateNenuphar(StrategyNenuphar& strategyNenuphar); // genère un nénuphar (etat passe à Grand) et assigne la strategie passée en paramètre
            DummyFropEtat& affectFroppie(int& pv)const; // affect froppy depending on the state and the strategy

        private:
            SurfEtat* _surfEtat;
            StrategyNenuphar* _strategyNenuphar;
        };
    }
}

#endif /* SURFACE_HPP */
