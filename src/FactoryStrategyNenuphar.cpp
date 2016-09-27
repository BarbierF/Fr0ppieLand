#include "include/FactoryStrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        const StrategyNenuphar& FactoryStrategyNenuphar::getEau(){
            if(!froppieLand::modele::FactoryStrategyNenuphar::_eau){
                froppieLand::modele::FactoryStrategyNenuphar::_eau = new froppieLand::modele::Eau();
            }
            return *(froppieLand::modele::FactoryStrategyNenuphar::_eau);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getImmortel(){
            if(!froppieLand::modele::FactoryStrategyNenuphar::_immortel){
                froppieLand::modele::FactoryStrategyNenuphar::_immortel = new froppieLand::modele::Immortel();
            }
            return *(froppieLand::modele::FactoryStrategyNenuphar::_immortel);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getVeneneux(){
            if(!froppieLand::modele::FactoryStrategyNenuphar::_veneneux){
                froppieLand::modele::FactoryStrategyNenuphar::_veneneux = new froppieLand::modele::Veneux();
            }
            return *(froppieLand::modele::FactoryStrategyNenuphar::_veneneux);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getNormal(){
            if(!froppieLand::modele::FactoryStrategyNenuphar::_normal){
                froppieLand::modele::FactoryStrategyNenuphar::_normal = new froppieLand::modele::Normal();
            }
            return *(froppieLand::modele::FactoryStrategyNenuphar::_normal);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getDopant(){
            if(!froppieLand::modele::FactoryStrategyNenuphar::_dopant){
                froppieLand::modele::FactoryStrategyNenuphar::_dopant = new froppieLand::modele::Dopant();
            }
            return *(froppieLand::modele::FactoryStrategyNenuphar::_dopant);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getMortel(){
            if(!froppieLand::modele::FactoryStrategyNenuphar::_mortel){
                froppieLand::modele::FactoryStrategyNenuphar::_mortel = new froppieLand::modele::Mortel();
            }
            return *(froppieLand::modele::FactoryStrategyNenuphar::_mortel);

        }

    }
}