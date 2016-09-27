#ifndef PETIT_HPP
#define PETIT_HPP
#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Petit:public SurfEtat{
        public:
            static SurfEtat& getInstance();
            const SurfEtat& age()const override;
        private:
            Petit();
        public:
        private:
            static Petit* _instance;
        };
    }
}

#endif /* PETIT_HPP */
