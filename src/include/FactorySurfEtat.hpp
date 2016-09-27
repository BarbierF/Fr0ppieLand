#ifndef FACTORYSURFETAT_HPP
#define FACTORYSURFETAT_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class FactorySurfEtat{
        public:
            static const SurfEtat& getInexistant();
            static const SurfEtat& getGrand();
            static const SurfEtat& getMoyen();
            static const SurfEtat& getPetit();
        private:
            static SurfEtat* _inexistant;
            static SurfEtat* _grand;
            static SurfEtat* _moyen;
            static SurfEtat* _petit;
        };
    }
}

#endif
