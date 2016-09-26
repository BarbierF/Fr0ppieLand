#ifndef INEXISTANT_HPP
#define INEXISTANT_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Inexistant:public SurfEtat{
        public:
            //const SurfEtat& get_instance() override;
            const int& get_size()const override;
        private:
            Inexistant();
        };
    }
}

#endif /* INEXISTANT_HPP */
