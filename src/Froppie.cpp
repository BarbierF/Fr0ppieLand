#include "include/froppie/Froppie.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            Froppie::Froppie(const int& pdv, const unsigned int& depX, const unsigned int& depY): _pointDeVie(pdv), _position({depX, depY}), _etat(&Sain::getSain()){
            }

            Froppie::~Froppie(){
            }

            const Position& Froppie::getPosition()const{
                return _position;
            }

            bool Froppie::deplacer(const Direction& direction, const unsigned int& tailleEnv){
                if(_position.X + direction.getVectorXDirection() > tailleEnv && _position.X + direction.getVectorXDirection() < tailleEnv
                    && _position.Y + direction.getVectorYDirection() > tailleEnv && _position.Y + direction.getVectorYDirection() < tailleEnv){
                        _position.X += direction.getVectorXDirection();
                        _position.Y += direction.getVectorYDirection();

                        _nbMove++;

                        return true;
                    }
                    else{
                        return false;
                    }

                
            }
            void Froppie::setSain(){
                _etat->setSain(*this);
            }
            void Froppie::setMalade(){
                _etat->setMalade(*this);
            }
            void Froppie::setMort(){
                _etat->setMort(*this);
            }

            void Froppie::subir(){
                _pointDeVie/=2;
                if(_pointDeVie == 0) setMort();
            }
            void Froppie::doper(){
                _pointDeVie*=2;
            }
            void Froppie::soigner(){
                _pointDeVie+=1;
            }
        }
        
    }
}
