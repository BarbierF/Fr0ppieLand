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
            SurfEtat* _inexistant;
            SurfEtat* _grand;
            SurfEtat* _moyen;
            SurfEtat* _petit;
        };
    }
}

#endif
