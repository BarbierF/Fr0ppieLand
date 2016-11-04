#include "Froppie.hpp"
#include "Sain.hpp"
#include "Malade.hpp"
#include "Mort.hpp"

namespace froppieLand{
    namespace modele{
        namespace froppie{
            Froppie::Froppie(const int pdv, const unsigned int depX, const unsigned int depY)
                : _pointDeVie(pdv), _position({depX, depY}), _etat(&Sain::getSain())
                {
                    
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

            const int& Froppie::getPDV()const{
                return _pointDeVie;
            }

            const unsigned int& Froppie::getNbMove()const{
                return _nbMove;
            }

            void Froppie::setSain(){
                _etat = &Sain::getSain();
            }

            void Froppie::setMalade(){
                _etat = &Malade::getMalade();
            }

            void Froppie::setMort(){
                _etat = &Mort::getMort();
            }

            const FropEtat& Froppie::getEtat()const{
                return *_etat;
            }

            void Froppie::subir(){
                _pointDeVie/=2;
                if(_pointDeVie == 0) _etat->setMort(*this);
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
