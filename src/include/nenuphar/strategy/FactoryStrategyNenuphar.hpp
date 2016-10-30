#ifndef FACTORYSTRATEGYNENUPHAR_HPP
#define FACTORYSTRATEGYNENUPHAR_HPP 

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class FactoryStrategyNenuphar{
            public:
                enum TypeNenu{
                    Eau,
                    Immortel,
                    Veneneux,
                    Normal,
                    Nutritif,
                    Dopant,
                    Mortel
                };
            
            public:
                static const StrateguNenuphar& getStrategy(TypeNenu type)const;
            private:
                static const StrategyNenuphar _eau;
                static const StrategyNenuphar _immortel;
                static const StrategyNenuphar _veneneux;
                static const StrategyNenuphar _normal;
                static const StrategyNenuphar _nutritif;
                static const StrategyNenuphar _dopant;
                static const StrategyNenuphar _mortel;
            };
        }
        
    }
}

#endif // FACTORYSTRATEGYNENUPHAR_HPP
