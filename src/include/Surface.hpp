#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "NomState.hpp"
#include "StrategyNenuphar.hpp"
namespace froppieLand{
		class Froppie;
		class Surface{
				public:
						Surface(const NomState& nomState, const StrategyNenuphar& strategyNenuphar);
						const NomState& get_state()const; //maybe get age instead?
						void set_strategy(const StrategyNenuphar& strategyNenuphar);
						const StrategyNenuphar& get_strategy()const;
						void affect_froppie(Froppie& froppie)const; // affect froppy depending on the state and the strategy
				private:
						NomState* _nomState;
						StrategyNenuphar* _strategyNenuphar;
		};
}

#endif /* SURFACE_HPP */
