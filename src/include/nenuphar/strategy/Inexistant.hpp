#ifndef INEXISTANT_HPP
#define INEXISTANT_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Inexistant:public SurfEtat{
            public:
                const SurfEtat& age()const override;
                const std::string nomStrategy()const override;
            private:
                Inexistant();
            private:
                static Inexistant* _instance;
            };
        }
        
    }
}

#endif /* INEXISTANT_HPP */
