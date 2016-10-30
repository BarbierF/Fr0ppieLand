#ifndef MOYEN_HPP
#define MOYEN_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Moyen:public SurfEtat{
            public:
                static SurfEtat const* getInstance();
                void age(Surface& victim)const override;

                const std::string nomEtat()const override;
            private:
                Moyen()=default;
            public:
            private:
                static const Moyen _moyen;
            };
        }
        
    }
}

#endif /* MOYEN_HPP */
