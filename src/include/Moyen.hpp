#ifndef MOYEN_HPP
#define MOYEN_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Moyen:public SurfEtat{
        public:
            static SurfEtat& getInstance();
            const SurfEtat& age()const override;
        private:
            Moyen();
        public:
        private:
            static Moyen* _instance;
        };
    }
}

#endif /* MOYEN_HPP */
