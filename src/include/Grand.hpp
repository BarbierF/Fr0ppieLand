#ifndef GRAND_HPP
#define GRAND_HPP


#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Grand:public SurfEtat{
        public:
            //const SurfEtat& get_instance() override;
            const int& get_size()const override;
        private:
            Grand();
        };
    }
}

#endif /* GRAND_HPP */
