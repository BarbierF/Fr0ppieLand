#ifndef SURFETAT_HPP
#define SURFETAT_HPP

#include <string>

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class SurfEtat{
                public:
                    virtual const SurfEtat& age()const=0;
                    virtual const std::string& nomEtat()const;
                };
        }
    }
}

#endif
