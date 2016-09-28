#include "include/Froppie.hpp"
#include "include/DirectionFactory.hpp"

namespace froppieLand{
    namespace modele{

        Froppie::Froppie(const int& pdv, const unsigned int& depX, const unsigned int& depY): _pointDeVie(pdv), _position({depX, depY}){
            _moveObservers = new std::list<FroppieMoveObserver*>();
        }

        Froppie::~Froppie(){
            delete _moveObservers;
        }

        const Position& Froppie::getPosition()const{
            return _position;
        }
        
        void Froppie::setPosition(int dX, int dY){
            _position.X += dX;
            _position.Y += dY;
            _nbMove++;
        }

        bool Froppie::deplacer(const Direction& direction, const unsigned int& tailleEnv){
            if(_position.X + direction.getVectorXDirection() > tailleEnv && _position.X + direction.getVectorXDirection() < tailleEnv
                && _position.Y + direction.getVectorYDirection() > tailleEnv && _position.Y + direction.getVectorYDirection() < tailleEnv){
                    _position.X += direction.getVectorXDirection();
                    _position.Y += direction.getVectorYDirection();

                    _nbMove++;
                    notifyMoveObservers();

                    return true;
                }
                else{
                    return false;
                }

            
        }

        void Froppie::notifyMoveObservers(){

            for(std::list<FroppieMoveObserver*>::iterator iter = _moveObservers->begin() ; iter != _moveObservers->end() ; ++iter){

                (*iter)->notifyMove();
            }
        }

        void Froppie::addMoveObserver(FroppieMoveObserver& abonne){
            _moveObservers->push_back(&abonne);
        }

        const bool& 
        Froppie::isSain() const {
            return _sain;
        }

        const bool& 
        Froppie::isMort() const {
            return _mort;
        }

        const bool& 
        Froppie::isMalade() const {
            return _malade;
        }

         void Froppie::setMalade() {
            if(!_malade) _malade =true;
            else _mort = true;
        }

        void Froppie::setSain() {
            _sain = true;
            _malade = false;
        }

        void Froppie::setMort() {
            _mort = true;
        }

        void Froppie::reduceHealth(){
            _pointDeVie/=2;
        }

        void Froppie::doubleHealth(){
            _pointDeVie*=2;
        }

        void Froppie::increaseHealth(){
            _pointDeVie+=1;
        }
    }
}
