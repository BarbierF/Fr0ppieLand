#ifndef MOYEN_HPP
#define MOYEN_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Moyen:public SurfEtat{
        public:
            //const SurfEtat& get_instance() override;
            const int& get_size()const override;
        private:
            Moyen();
        };
    }
}

#endif /* MOYEN_HPP */
