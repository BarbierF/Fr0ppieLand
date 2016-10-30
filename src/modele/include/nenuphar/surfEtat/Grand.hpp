#ifndef GRAND_HPP
#define GRAND_HPP


#include "SurfEtat.hpp"

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Grand:public SurfEtat{
            public:
                static SurfEtat const* getInstance();
                void age(Surface& victim)const override;

                const std::string nomEtat()const override;
            private:
                Grand()=default;
            public:
            private:
                static const Grand _grand;
            };
        }
        
    }
}

#endif /* GRAND_HPP */
