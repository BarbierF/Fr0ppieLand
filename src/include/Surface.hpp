#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "SurfEtat.hpp"
#include "StrategyNenuphar.hpp"
#include "FropEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Froppie;
        class Surface{
        public:
            Surface(SurfEtat& surfEtat, StrategyNenuphar& strategyNenuphar);
            Surface();
            const SurfEtat& getEtat()const;
            void setStrategy(StrategyNenuphar& strategyNenuphar);
            const StrategyNenuphar& getStrategy()const;
            void age(); //fait viellir le nenuphar
            void generateNenuphar(StrategyNenuphar& strategyNenuphar); // genère un nénuphar (etat passe à Grand) et assigne la strategie passée en paramètre
            void souffrir(Froppie& victim)const;

        private:
            SurfEtat* _surfEtat;
            StrategyNenuphar* _strategyNenuphar;
            const Position _sPosition;
        };
    }
}

#endif /* SURFACE_HPP */
