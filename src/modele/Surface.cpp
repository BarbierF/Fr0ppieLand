#include "include/nenuphar/Surface.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            Surface::Surface(SurfEtat const* surfEtat, StrategyNenuphar const* strategyNenuphar, unsigned int iS, unsigned int jS)
            :_etat(surfEtat), _strategy(strategyNenuphar), _sPosition({iS, jS}) {

            }

            Surface::Surface(unsigned int iS, unsigned int jS):
            _etat(Inexistant::getInstance()), _strategy(FactoryStrategyNenuphar::getStrategy(TypeNenu::eau)), _sPosition({iS, jS}){

            }

            const SurfEtat& Surface::getEtat()const {
                return *_etat;
            }

            void Surface::setStrategy(StrategyNenuphar const* strategyNenuphar) {
                _strategy = strategyNenuphar;
            }

            const StrategyNenuphar& Surface::getStrategy()const {
                return *_strategy;
            }

            void Surface::age() {
                _strategy->vieillir(*this);
            }

            void Surface::generateNenuphar(StrategyNenuphar const* strategyNenuphar){
                _etat = Grand::getInstance();
                _strategy = strategyNenuphar;
            }
            void Surface::souffrir(froppie::Froppie& victim)const{
                _strategy->souffrir(victim);
            }

            void Surface::vieillirEtat(){
                _etat->age(*this);
            }

            void Surface::setEtat(SurfEtat const* nEtat){
                _etat = nEtat;
            }
        }        
    }
}