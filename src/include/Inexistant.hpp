#ifndef INEXISTANT_HPP
#define INEXISTANT_HPP

namespace froppieLand{
		class Inexistant:public NomState{
				public:
						const NomState& get_instance() override;
						const int& get_size()const override;
				private:
						Inexistant();
		};
}

#endif /* INEXISTANT_HPP */
