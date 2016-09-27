#ifndef INEXISTANT_HPP
#define INEXISTANT_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Inexistant:public SurfEtat{
        public:
            static SurfEtat& getInstance();
            const SurfEtat& age()const override;
        private:
            Inexistant();
        public:
        private:
            static Inexistant* _instance;
        };
    }
}

#endif /* INEXISTANT_HPP */
