#include "include/nenuphar/Surface.hpp"

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
            *_strategy.souffrir(*this);
        }

        void Surface::generateNenuphar(StrategyNenuphar* strategyNenuphar){
            _surfEtat = &Grand::getInstance();
            _strategyNenuphar = strategyNenuphar;
        }
        void Surface::souffrir(Froppie& victim)const{
            _strategyNenuphar->souffrir(victim);
        }

        void nextEtat(){
            _etat.age(*this);
        }
    }
}
