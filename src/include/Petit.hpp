#ifndef PETIT_HPP
#define PETIT_HPP
#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Petit:public SurfEtat{
        public:
            //const SurfEtat& get_instance()override;
            const int& get_size()const override;
        private:
            Petit();
        };
    }
}

#endif /* PETIT_HPP */
