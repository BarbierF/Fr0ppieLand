#include "include/Surface.hpp"
#include "include/Grand.hpp"

namespace froppieLand{
    namespace modele{
        
        Surface::Surface(SurfEtat& surfEtat, StrategyNenuphar& strategyNenuphar):_surfEtat(&surfEtat), _strategyNenuphar(&strategyNenuphar), _sPosition({iS, jS}) {
    
        }

        Surface::Surface(): _surfEtat(&Inexistant::getInstance()), _strategyNenuphar(&FactoryStrategyNenuphar::getEau(), _sPosition({iS, jS})){

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
            if(_strategyNenuphar->canDie())
                _surfEtat->age();
        }

        void Surface::generateNenuphar(StrategyNenuphar& strategyNenuphar){
            _surfEtat = &Grand::getInstance();
            _strategyNenuphar = &strategyNenuphar;
        }

        // const FropEtat& Surface::affectFropEtat()const {
        //     return _strategyNenuphar->affectFropEtat();
        // }

        // const int& Surface::affectHealth(const int& pv)const {
        //     return _strategyNenuphar->affectHealth(pv);
        // }
        void Surface::souffrir(Froppie& victim)const{
            _strategyNenuphar->souffrir(victim);
        }
    }
}
