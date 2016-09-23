#ifndef PETIT_HPP
#define PETIT_HPP
#include "include/NomState.hpp"

namespace froppie{
		class Petit:public NomState{
				public:
						const NomState& get_instance()override;
						const int& get_size()const override;
				private:
						Petit();
		};
}

#endif /* PETIT_HPP */
