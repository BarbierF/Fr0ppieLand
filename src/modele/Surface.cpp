#include "Surface.hpp"

#include "Nord.hpp"
#include "Sud.hpp"
#include "Ouest.hpp"
#include "Est.hpp"

#include <iostream>

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            Surface::Surface(SurfEtat const* surfEtat
            , StrategyNenuphar const* strategyNenuphar
            , unsigned int iS
            , unsigned int jS
            , const unsigned int& dimension)
                :_etat(surfEtat)
                , _strategy(strategyNenuphar)
                , _sPosition(iS, jS)
                , _iterVoisin(_sPosition)
                , _voisins(genererMapVoisins(dimension)) {

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

            std::map < Position, Direction const* > Surface::genererMapVoisins(
                const unsigned int& dimension
            )const{
                
                std::map < Position, Direction const* > result;
                
                Nord const* nord = Nord::getNord();
                Position nordCase(
                    _sPosition.getLigne() + nord.getVectorYDirection()
                    , _sPosition.getColonne() + nord.getVectorXDirection());
                
                if(nordCase.getLigne() < _taille && nordCase.getColonne < _taille){
                    result[nordCase] = nord;
                }

                Sud const* sud = Sud::getSud();
                Position sudCase(
                    _sPosition.getLigne() + sud.getVectorYDirection()
                    , _sPosition.getColonne() + sud.getVectorXDirection());

                if(sudCase.getLigne() < _taille && sudCase.getColonne() < _taille){
                    result[sudCase] = sud;
                }

                Ouest const* ouest = Ouest::getOuest();
                Position ouestCase(
                    _sPosition.getLigne() + ouest.getVectorYDirection()
                    , _sPosition.getColonne() + ouest.getVectorXDirection());

                if(ouestCase.getLigne() < _taille && ouestCase.getColonne() < _taille){
                    result[ouestCase] = ouest;
                }

                Est const* est = Est::getEst();
                Position ouestCase(
                    _sPosition.getLigne() + est.getVectorYDirection()
                    , _sPosition.getColonne() + est.getVectorXDirection());

                if(estCase.getLigne() < _taille && estCase.getColonne() < _taille){
                    result[estCase] = est;
                }
                
                //utiliser des pair de unsigend int 
                return result;
            }

            void Surface::setEtat(SurfEtat const* nEtat){
                _etat = nEtat;
            }

            bool Surface::isCaseVoisine(const unsigned int& ligne, const unsigned int& colonne){
                /*bool result = false;

                unsigned int vLigne = ligne, vColonne = colonne; 
                _iterVoisin.setVoisinPotentiel(vLigne, vColonne);
                
                while(!_iterVoisin.isFini() && !result){
                    
                    result = _iterVoisin.voisinSuivant();
                }

                return result;*/
            }

            Direction const* Surface::getDirectionVoisin()const{
                return _iterVoisin.getDirectionActuelle();
            }
        }        
    }
}
