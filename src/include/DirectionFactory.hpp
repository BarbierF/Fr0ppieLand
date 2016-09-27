#ifndef DIRECTION_FACTORY
#define DIRECTION_FACTORY

#include "Directions.hpp"
#include "NonCopyable.hpp"

namespace froppieLand{
    namespace modele{

        class DirectionFactory: NonCopyable{
        private:
            static DirectionFactory _instance;
            
            DirectionFactory();
            ~DirectionFactory();

            static Nord _nord;
            static Sud _sud;
            static Ouest _ouest;
            static Est _est;

        public:
            static const DirectionFactory& getInstance();
            
            static const Nord& getNord();
            static const Sud& getSud();
            static const Ouest& getOuest();
            static const Est& getEst(); 
        };
    }
}

#endif