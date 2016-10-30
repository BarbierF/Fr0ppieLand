#ifndef FACTORYSTRATEGYNENUPHAR_HPP
#define FACTORYSTRATEGYNENUPHAR_HPP 

#include "Eau.hpp"
#include "Immortel.hpp"
#include "Veneneux.hpp"
#include "Normal.hpp"
#include "Nutritif.hpp"
#include "Dopant.hpp"
#include "Mortel.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class FactoryStrategyNenuphar{
            public:
                enum TypeNenu{
                    eau,
                    immortel,
                    veneneux,
                    normal,
                    nutritif,
                    dopant,
                    mortel
                };

            public:
                static StrategyNenuphar const* getStrategy(TypeNenu type);
            private:
                static const Eau _eau;
                static const Immortel _immortel;
                static const Veneneux _veneneux;
                static const Normal _normal;
                static const Nutritif _nutritif;
                static const Dopant _dopant;
                static const Mortel _mortel;
            };
        }
        
    }
}

#endif // FACTORYSTRATEGYNENUPHAR_HPP
