#ifndef GRAND_HPP
#define GRAND_HPP


#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        class Grand:public SurfEtat{
        public:
            static SurfEtat& getInstance();
            const SurfEtat& age()const override;
        private:
            Grand();
        public:
        private:
            static Grand* _instance;
        };
    }
}

#endif /* GRAND_HPP */
