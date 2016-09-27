#ifndef FACTORYSTRATEGYNENUPHAR_HPP
#define FACTORYSTRATEGYNENUPHAR_HPP 1

#include "StrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{
        class FactoryStrategyNenuphar{
        public:
            static const StrategyNenuphar& getEau();
            static const StrategyNenuphar& getImmortel();
            static const StrategyNenuphar& getVeneneux();
            static const StrategyNenuphar& getNormal();
            static const StrategyNenuphar& getNutritif();
            static const StrategyNenuphar& getDopant();
            static const StrategyNenuphar& getMortel();
        private:
            static StrategyNenuphar* _eau;
            static StrategyNenuphar* _immortel;
            static StrategyNenuphar* _veneneux;
            static StrategyNenuphar* _normal;
            static StrategyNenuphar* _nutritif;
            static StrategyNenuphar* _dopant;
            static StrategyNenuphar* _mortel;
        };
    }
}

#endif // FACTORYSTRATEGYNENUPHAR_HPP
