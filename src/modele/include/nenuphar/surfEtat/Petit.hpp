#ifndef PETIT_HPP
#define PETIT_HPP
#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Petit:public SurfEtat{
            public:
                static SurfEtat const* getInstance();
                void age(Surface& victim)const override;

                const std::string nomEtat()const;
            private:
                Petit()=default;
            public:
            private:
                static const Petit _petit;
            };
        }
        
    }
}

#endif /* PETIT_HPP */
