#include "include/DirectionFactory.hpp"
#include "include/Directions.hpp"

namespace froppieLand{
    namespace modele{
        

        DirectionFactory DirectionFactory::_instance = DirectionFactory();
        Nord DirectionFactory::_nord = Nord();
        Sud DirectionFactory::_sud = Sud();
        Est DirectionFactory::_est = Est();
        Ouest DirectionFactory::_ouest = Ouest();
        
        DirectionFactory::DirectionFactory(){
        }
        DirectionFactory::~DirectionFactory(){
        }

        const DirectionFactory& DirectionFactory::getInstance(){
            return _instance;
        }

        const Nord& DirectionFactory::getNord(){
            return _nord;
        }
        const Sud& DirectionFactory::getSud(){
            return _sud;
        }
        const Ouest& DirectionFactory::getOuest(){
            return _ouest;
        }
        const Est& DirectionFactory::getEst(){
            return _est;
        }
    }
}