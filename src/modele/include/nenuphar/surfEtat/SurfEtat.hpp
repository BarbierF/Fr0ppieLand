#ifndef SURFETAT_HPP
#define SURFETAT_HPP

#include <string>

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Surface;
            class SurfEtat{
                public:
                    virtual void age(Surface& victim)const=0;
                    virtual const std::string nomEtat()const=0;
                };
        }
    }
}

#endif
