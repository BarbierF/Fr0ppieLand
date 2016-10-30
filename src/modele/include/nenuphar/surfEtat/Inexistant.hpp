#ifndef INEXISTANT_HPP
#define INEXISTANT_HPP

#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Inexistant:public SurfEtat{
            public:
                void age(Surface& victim)const override;
                const std::string nomEtat()const override;

                static SurfEtat const* getInstance();
            private:
                Inexistant()=default;
            private:
                static const Inexistant _inexistant;
            };
        }
        
    }
}

#endif /* INEXISTANT_HPP */
