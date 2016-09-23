#ifndef EAU_HPP
#define EAU_HPP

#include "StrategyNenuphar.hpp"

namespace froppieLand{
		class Eau: public StateNenuphar{
				public:
						const StateNenuphar& get_instance();
						const bool& can_die()const;
						const int& affect_health()const;
						const bool& can_kill()const =0;
						void affect_froppie(Froppie& froppie)const;
		};
}


#endif /* EAU_HPP */
