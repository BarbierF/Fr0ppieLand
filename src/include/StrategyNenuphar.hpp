#ifndef STRATEGYNENUPHAR_HPP
#define STRATEGYNENUPHAR_HPP

namespace froppieLand{
		class Froppie;
		class StrategyNenuphar{
				public: 
						virtual const StrategyNenuphar& get_instance()=0;
						virtual const bool& can_die()const =0;
						virtual const int& affect_health()const =0;
						virtual const bool& can_kill()const =0;
						virtual void affect_froppie(Froppie& froppie)const=0;
				protected:
						static StrategyNenuphar* _instance;
		};
}

#endif /* STRATEGYNENUPHAR_HPP */
