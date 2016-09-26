#include "include/Surface.hpp"
#include "include/FactorySurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        
        Surface::Surface(SurfEtat& surfEtat, StrategyNenuphar& strategyNenuphar):_surfEtat(&surfEtat), _strategyNenuphar(&strategyNenuphar) {
    
        }

        const SurfEtat& Surface::getEtat()const {
            return *_surfEtat;
        }

        void Surface::setStrategy(StrategyNenuphar& strategyNenuphar) {
            _strategyNenuphar = &strategyNenuphar;
        }

        const StrategyNenuphar& Surface::getStrategy()const {
            return *_strategyNenuphar;
        }

        void Surface::age() {
            _surfEtat->age();
        }

        void Surface::generateNenuphar(StrategyNenuphar& strategyNenuphar){
            FactorySurfEtat::getGrand();
            _strategyNenuphar = &strategyNenuphar;
        }

        DummyFropEtat& Surface::affectFroppie(int& pv)const {
            return _strategyNenuphar->affectFroppie(pv);
        }
    }
}
