#include "Froppie.hpp"
#include "Sain.hpp"
#include "Malade.hpp"
#include "Mort.hpp"

#include <iostream>

namespace froppieLand{
    namespace modele{
        namespace froppie{
            Froppie::Froppie(const int pdv, const unsigned int depLigne, const unsigned int depColonne)
                : _pointDeVie(pdv), _position(depLigne, depColonne), _etat(&Sain::getSain())
                {
                    std::cout << _position.getLigne() << ";" << _position.getColonne() << std::endl;
            }

            Froppie::~Froppie(){
            }

            const Position& Froppie::getPosition()const{
                return _position;
            }

            const Position& Froppie::deplacer(const Direction& direction){
                
                _position.changeValue(direction);
                _nbMove++;
                return _position;
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
                _pointDeVie = 0;
                _etat = &Mort::getMort();
            }

            const FropEtat& Froppie::getEtat()const{
                return *_etat;
            }

            void Froppie::subir(){
                if(_pointDeVie != 0)_pointDeVie/=2;
                else _pointDeVie = 0;

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
