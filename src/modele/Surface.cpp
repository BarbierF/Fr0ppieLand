#include "Surface.hpp"
#include <iostream>

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            Surface::Surface(SurfEtat const* surfEtat, StrategyNenuphar const* strategyNenuphar, unsigned int iS, unsigned int jS)
            :_etat(surfEtat), _strategy(strategyNenuphar), _sPosition(iS, jS), _iterVoisin(_sPosition) {

            }

            Surface::Surface(unsigned int iS, unsigned int jS)
                : _etat(Inexistant::getInstance())
                , _strategy(FactoryStrategyNenuphar::getStrategy(TypeNenu::eau))
                , _sPosition({iS, jS})
                , _iterVoisin(_sPosition){

            }

            const SurfEtat& Surface::getEtat()const {
                return *_etat;
            }

            void Surface::setStrategy(StrategyNenuphar const* strategyNenuphar) {
                _strategy = strategyNenuphar;
            }

            const StrategyNenuphar& Surface::getStrategy()const {
                return *_strategy;
            }

            const unsigned int& Surface::getLigne()const{
                return _sPosition.getLigne();
            }

            const unsigned int& Surface::getColonne()const{
                return _sPosition.getColonne();
            }

            void Surface::age() {
                _strategy->vieillir(*this);
            }

            void Surface::generateNenuphar(StrategyNenuphar const* strategyNenuphar){
                _etat = Grand::getInstance();
                _strategy = strategyNenuphar;
            }
            void Surface::souffrir(froppie::Froppie& victim)const{
                _strategy->souffrir(victim);
            }

            void Surface::vieillirEtat(){
                _etat->age(*this);
            }

            void Surface::setEtat(SurfEtat const* nEtat){
                _etat = nEtat;
            }

            bool Surface::isCaseVoisine(const unsigned int& ligne, const unsigned int& colonne){
                bool result = false;

                unsigned int vLigne = ligne, vColonne = colonne; 
                _iterVoisin.setVoisinPotentiel(vLigne, vColonne);
                
                while(!_iterVoisin.isFini() && !result){
                    
                    result = _iterVoisin.voisinSuivant();
                }

                return result;
            }

            Direction const* Surface::getDirectionVoisin()const{
                return _iterVoisin.getDirectionActuelle();
            }
        }        
    }
}
