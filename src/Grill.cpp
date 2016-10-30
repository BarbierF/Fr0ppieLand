#include <cmath>
#include <random>

#include "include/Grill.hpp"
#include "include/nenuphar/strategy/FactoryStrategyNenuphar.hpp"


namespace froppieLand{
    namespace modele{
        Grill::Grill(unsigned int taille, unsigned int posXD, unsigned int posYD, unsigned int posXA, unsigned int posYA):
            _taille(taille), _depart({posXD, posYD}), _arrivee({posXA, posYA})
        {
            _terrain.reserve(_taille * _taille);

            _froppie = new Froppie(10, _depart.X, _depart.Y);
            _froppie->addMoveObserver(this);
        }

        const Position& Grill::getDepart()const{
            return _depart;
        } 
        const Position& Grill::getArrivee()const{
            return _arrivee;
        }
        Froppie& Grill::getFroppie()const{
            return *_froppie;
        }
        const Surface& Grill::getCase(unsigned int X, unsigned int Y)const{
            return *_terrain[X * _taille + Y];
        }

        void Grill::vieilissement(){
            for(int i = 0 ; i < _taille ; i++){
                for(int j = 0 ; j < _taille ; j++){
                    _terrain[i * _taille + j]->age();
                }
            }
        }

        void Grill::consChemin()const{

            std::linear_congruential_engine generateur;
            std::uniforme_int_distribution<int> distribution(0, 7); //On va générer les nombres de 1 à 7.

            const Position& fropPosition = _froppie->getPosition();
            if(fropPosition.X == _arrivee.X){
                for(int i = 0 ; i < std::abs(_arrivee.Y - fropPosition.Y) ; i++){

                    StrategyNenuphar* nenuStrat = FactoryStrategyNenuphar::getStrategy(distribution(generator));
                    _terrain[fropPosition.X * _taille + i]->generateNenuphar(nenuStrat);
                }
            }
            else if(fropPosition.Y == _arrivee.Y){
                for(int i = 0 ; i < std::abs(_arrivee.X - fropPosition.Y) ; i++){

                    StrategyNenuphar* nenuStrat = FactoryStrategyNenuphar::getStrategy(distribution(generator));
                    _terrain[i * _taille + fropPosition.Y]->generateNenuphar(nenuStrat);
                }
            }
            else{
                for(int i = 0 ; i < std::abs(_arrivee.X - fropPosition.X) ; i++){
                    for(int j = 0 ; j < std::abs(_arrivee.Y - fropPosition.Y) ; j++){
                        
                        StrategyNenuphar* nenuStrat = FactoryStrategyNenuphar::getStrategy(distribution(generator));
                        _terrain[i * _taille + j]->generateNenuphar(nenuStrat);
                    }
                }
            }
        }
        
    }
}


