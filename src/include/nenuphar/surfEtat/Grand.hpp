#ifndef GRAND_HPP
#define GRAND_HPP


#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Grand:public SurfEtat{
            public:
                static SurfEtat& getInstance();
                const SurfEtat& age()const override;

                const std::string& nomEtat()const override;
            private:
                Grand();
            public:
            private:
                static Grand* _instance;
            };
        }
        
    }
}

#endif /* GRAND_HPP */
