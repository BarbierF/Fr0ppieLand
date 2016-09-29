#include "include/FactoryStrategyNenuphar.hpp"
#include "include/Eau.hpp"
#include "include/Normal.hpp"
#include "include/Immortel.hpp"
#include "include/Veneneux.hpp"
#include "include/Nutritif.hpp"
#include "include/Dopant.hpp"
#include "include/Mortel.hpp"

namespace froppieLand{
    namespace modele{
        StrategyNenuphar* FactoryStrategyNenuphar::_eau=nullptr;
        StrategyNenuphar* FactoryStrategyNenuphar::_immortel=nullptr;
        StrategyNenuphar* FactoryStrategyNenuphar::_veneneux=nullptr;
        StrategyNenuphar* FactoryStrategyNenuphar::_normal=nullptr;
        StrategyNenuphar* FactoryStrategyNenuphar::_nutritif=nullptr;
        StrategyNenuphar* FactoryStrategyNenuphar::_dopant=nullptr;
        StrategyNenuphar* FactoryStrategyNenuphar::_mortel=nullptr;
        const StrategyNenuphar& FactoryStrategyNenuphar::getEau(){
            if(!FactoryStrategyNenuphar::_eau){
                FactoryStrategyNenuphar::_eau = new Eau();
            }
            return *(FactoryStrategyNenuphar::_eau);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getImmortel(){
            if(!_immortel){
                FactoryStrategyNenuphar::_immortel = new Immortel();
            }
            return *(_immortel);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getVeneneux(){
            if(!_veneneux){
                FactoryStrategyNenuphar::_veneneux = new Veneneux();
            }
            return *(FactoryStrategyNenuphar::_veneneux);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getNormal(){
            if(!FactoryStrategyNenuphar::_normal){
                FactoryStrategyNenuphar::_normal = new Normal();
            }
            return *(FactoryStrategyNenuphar::_normal);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getDopant(){
            if(!FactoryStrategyNenuphar::_dopant){
                FactoryStrategyNenuphar::_dopant = new Dopant();
            }
            return *(FactoryStrategyNenuphar::_dopant);

        }

        const StrategyNenuphar& FactoryStrategyNenuphar::getMortel(){
            if(!FactoryStrategyNenuphar::_mortel){
                FactoryStrategyNenuphar::_mortel = new Mortel();
            }
            return *(FactoryStrategyNenuphar::_mortel);

        }

    }
}
