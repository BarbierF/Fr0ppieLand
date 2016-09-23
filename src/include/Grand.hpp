#ifndef GRAND_HPP
#define GRAND_HPP

namespace froppieLand{
		class Grand:public NomState{
				public:
						const NomState& get_instance() override;
						const int& get_size()const override;
				private:
						Grand();
		};
}

#endif /* GRAND_HPP */
