#include "include/nenuphar/strategy/FactoryStrategyNenuphar.hpp"
#include "include/nenuphar/strategy/Eau.hpp"
#include "include/nenupar/strategy/Normal.hpp"
#include "include/nenuphar/strategy/Immortel.hpp"
#include "include/nenuphar/strategy/Veneneux.hpp"
#include "include/nenuphar/strategy/Nutritif.hpp"
#include "include/nenuphar/strategy/Dopant.hpp"
#include "include/nenuphar/strategy/Mortel.hpp"

namespace froppieLand{
    namespace modele{
        const StrategyNenuphar FactoryStrategyNenuphar::_eau();
        const StrategyNenuphar FactoryStrategyNenuphar::_immortel();
        const StrategyNenuphar FactoryStrategyNenuphar::_veneneux();
        const StrategyNenuphar FactoryStrategyNenuphar::_normal();
        const StrategyNenuphar FactoryStrategyNenuphar::_nutritif();
        const StrategyNenuphar FactoryStrategyNenuphar::_dopant();
        const StrategyNenuphar FactoryStrategyNenuphar::_mortel();
        
        const StrategyNenuphar* const getStrategy(TypeNenu type){
            switch(type){

                case Eau :
                    return &_eau;
                    break;

                case Immortel :
                    return &_immortel;
                    break;

                case Veneneux :
                    return &_veneneux;
                    break;

                case Normal :
                    return &_normal;
                    break;

                case Nutritif :
                    return _nutritif;
                    break;

                case Dopant :
                    return _dopant;
                    break;

                case Mortel : 
                    return _mortel;
                    break;                
            }
        }

    }
}
