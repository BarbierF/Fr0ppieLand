#ifndef MOYEN_HPP
#define MOYEN_HPP

namespace froppie{
		class Moyen:public NomState{
				public:
						const NomState& get_instance() override;
						const int& get_size()const override;
				private:
						Moyen();
		};
}

#endif /* MOYEN_HPP */
