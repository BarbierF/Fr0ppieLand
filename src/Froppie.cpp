#include "include/Froppie.hpp"
#include "include/DirectionFactory.hpp"
#include "include/Sain.hpp"

namespace froppieLand{
    namespace modele{

        Froppie::Froppie(const int& pdv, const unsigned int& depX, const unsigned int& depY): _pointDeVie(pdv), _position({depX, depY}), _etat(&Sain::getSain()){
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

        const FropEtat& Froppie::getCurEtat()const{
            return *_etat;
        }
        void Froppie::setEtat(const FropEtat& nEtat){
            _etat = &nEtat;
        }
    }
}