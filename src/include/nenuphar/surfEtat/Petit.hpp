#ifndef PETIT_HPP
#define PETIT_HPP
#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Petit:public SurfEtat{
            public:
                static SurfEtat& getInstance();
                const SurfEtat& age()const override;

                const std::string& nomEtat()const;
            private:
                Petit();
            public:
            private:
                static Petit* _instance;
            };
        }
        
    }
}

#endif /* PETIT_HPP */
