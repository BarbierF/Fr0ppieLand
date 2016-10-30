#include "include/nenuphar/strategy/FactoryStrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            const Eau FactoryStrategyNenuphar::_eau;
            const Immortel FactoryStrategyNenuphar::_immortel;
            const Veneneux FactoryStrategyNenuphar::_veneneux;
            const Normal FactoryStrategyNenuphar::_normal;
            const Nutritif FactoryStrategyNenuphar::_nutritif;
            const Dopant FactoryStrategyNenuphar::_dopant;
            const Mortel FactoryStrategyNenuphar::_mortel;
            
            StrategyNenuphar const* FactoryStrategyNenuphar::getStrategy(TypeNenu type){
                switch(type){

                    case eau :
                        return &_eau;
                        break;

                    case immortel :
                        return &_immortel;
                        break;

                    case veneneux :
                        return &_veneneux;
                        break;

                    case normal :
                        return &_normal;
                        break;

                    case nutritif :
                        return &_nutritif;
                        break;

                    case dopant :
                        return &_dopant;
                        break;

                    case mortel : 
                        return &_mortel;
                        break;                
                }
            }
        }
    }
}
