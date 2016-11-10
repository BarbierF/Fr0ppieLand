#include "Surface.hpp"

#include "Nord.hpp"
#include "Sud.hpp"
#include "Ouest.hpp"
#include "Est.hpp"

#include <iostream>

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            Surface::Surface(unsigned int iS
            , unsigned int jS
            , const unsigned int& dimension)
                : _sPosition(iS, jS)
                , _etat(Inexistant::getInstance())
                , _strategy(FactoryStrategyNenuphar::getStrategy(TypeNenu::eau))
                , _voisins(genererMapVoisins(dimension)) {
                    
            }

            Surface::~Surface(){
                _etat = nullptr;
                _strategy = nullptr;
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

            const std::map < Position, Direction const*>& Surface::getVoisinnage()const{
                return _voisins;
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
                
                Nord const* nord = &Nord::getNord();
                Position nordCase(
                    static_cast < unsigned int > (static_cast < int > (_sPosition.getLigne()) + nord->getVectorYDirection())
                    , static_cast < unsigned int > (static_cast < int > (_sPosition.getColonne()) + nord->getVectorXDirection()));
                
                if(nordCase.getLigne() < dimension && nordCase.getColonne() < dimension){
                    result[nordCase] = nord;
                }

                Sud const* sud = &Sud::getSud();
                Position sudCase(
                    static_cast < unsigned int > (static_cast < int > (_sPosition.getLigne()) + sud->getVectorYDirection())
                    , static_cast < unsigned int > (static_cast < int > (_sPosition.getColonne()) + sud->getVectorXDirection()));

                if(sudCase.getLigne() < dimension && sudCase.getColonne() < dimension){
                    result[sudCase] = sud;
                }

                Ouest const* ouest = &Ouest::getOuest();
                Position ouestCase(
                    static_cast < unsigned int > (static_cast < int > (_sPosition.getLigne()) + ouest->getVectorYDirection())
                    , static_cast < unsigned int > (static_cast < int > (_sPosition.getColonne()) + ouest->getVectorXDirection()));

                if(ouestCase.getLigne() < dimension && ouestCase.getColonne() < dimension){
                    result[ouestCase] = ouest;
                }

                Est const* est = &Est::getEst();
                Position estCase(
                    static_cast < unsigned int > (static_cast < int > (_sPosition.getLigne()) + est->getVectorYDirection())
                    , static_cast < unsigned int > (static_cast < int > (_sPosition.getColonne()) + est->getVectorXDirection()));

                if(estCase.getLigne() < dimension && estCase.getColonne() < dimension){
                    result[estCase] = est;
                }

                
                std::cout << "Position :  " << _sPosition.getLigne() << ";" << _sPosition.getColonne() << std::endl;
                
                for(auto it = _voisins.begin() ; it != _voisins.end() ; ++it){
                    Position pos = it->first;
                    const Direction* dire = it->second;
                    std::cout << pos.getLigne() << ";" << pos.getColonne() << std::endl;
                    std::cout << dire->getVectorXDirection() << ";" << dire->getVectorYDirection() << std::endl;
                }

                return result;
            }

            void Surface::setEtat(SurfEtat const* nEtat){
                _etat = nEtat;
            }

            bool Surface::isCaseVoisine(const unsigned int& ligne, const unsigned int& colonne)const{
                
                return _voisins.find(Position(ligne, colonne)) != _voisins.end();
            }

            Direction const* Surface::getDirectionVoisin(const unsigned int& ligne, const unsigned int& colonne){
                Direction const* surf = _voisins[Position(ligne, colonne)];
                std::cout << "Position :  " << _sPosition.getLigne() << ";" << _sPosition.getColonne() << std::endl;
                
                for(auto it = _voisins.begin() ; it != _voisins.end() ; ++it){
                    Position pos = it->first;
                    const Direction* dire = it->second;
                    std::cout << pos.getLigne() << ";" << pos.getColonne() << std::endl;
                    std::cout << dire->getVectorXDirection() << ";" << dire->getVectorYDirection() << std::endl;
                }

                return _voisins[Position(ligne, colonne)];
            }
        }        
    }
}
