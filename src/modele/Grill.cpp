#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Grill.hpp"
#include "FactoryStrategyNenuphar.hpp"
#include <iostream>


namespace froppieLand{
    namespace modele{

        
        Grill::Grill(
            unsigned int taille
            , unsigned int posLigneD
            , unsigned int posColonneD
            , unsigned int posLigneA
            , unsigned int posColonneA)
            : _froppie(1, posLigneD, posColonneD)
            , _taille(taille)
            , _depart(posLigneD, posColonneD)
            , _arrivee(posLigneA, posColonneA)
        {
            
            _terrain.reserve(_taille * _taille);
            for(unsigned int i = 0 ; i < _taille ; i++){
                for(unsigned int j = 0 ; j < _taille ; j++){
                    
                    _terrain.push_back(Surface(i, j, _taille));
                }
            }


            _terrain[ posLigneD * _taille + posColonneD ].generateNenuphar(
                nenuphar::FactoryStrategyNenuphar::getStrategy(Surface::TypeNenu::immortel)
            );

            _terrain[ posLigneA * _taille + posColonneA ].generateNenuphar(
                nenuphar::FactoryStrategyNenuphar::getStrategy(Surface::TypeNenu::immortel)
            );

            for(std::vector<Surface>::iterator it = _terrain.begin() ; it != _terrain.end() ; ++it){
                std::cout << "Ligne : " << it->getLigne() << " Colonne : " << it->getColonne() << std::endl;
            }

        }

        const unsigned int& Grill::getTaille()const{
            
            return _taille;
        }

        const Position& Grill::getDepart()const{
            return _depart;
        }

        const Position& Grill::getArrivee()const{
            return _arrivee;
        }

        Grill::Froppie& Grill::getModifFroppie(){
            return _froppie;
        }

        const Grill::Froppie& Grill::getFroppie()const{
            return _froppie;
        }
        
        const Grill::Surface& Grill::getSurface(const unsigned int& ligne, const unsigned int& colonne)const{
            return _terrain[ligne * _taille + colonne];
        }

        Grill::Surface& Grill::getSurfaceModifiable(const unsigned int& ligne, const unsigned int& colonne){
            return _terrain[ligne * _taille + colonne];
        }

        const Grill::Surface& Grill::getFroppieSurf()const{
            Position fropPos = _froppie.getPosition();

            return _terrain[fropPos.getLigne() * _taille + fropPos.getColonne()];
        }

        Grill::Surface& Grill::getModifFroppieSurf(){
            Position fropPos = _froppie.getPosition();
            
            return _terrain[fropPos.getLigne() * _taille + fropPos.getColonne()];
        }

        void Grill::vieillissement(){
            for(unsigned int i = 0 ; i < _taille ; i++){
                for(unsigned int j = 0 ; j < _taille ; j++){
                    _terrain[i * _taille + j].age();
                }
            }
        }

        void Grill::construireChemin(){

            srand(time(NULL));

            const Position& fropPosition = _froppie.getPosition();
            std::cout << "FropPosition : Ligne = " <<  fropPosition.getLigne() << " Colonne = " << fropPosition.getColonne() << std::endl;
            
            if(fropPosition.getLigne() == _arrivee.getLigne()){

                if(fropPosition.getColonne() < _arrivee.getColonne())
                    for(unsigned int i = fropPosition.getColonne() + 1
                    ; i < _arrivee.getColonne()
                    ; i++){
                            adapterSurface(fropPosition.getLigne(), i);

                    }

                if(fropPosition.getColonne() > _arrivee.getColonne())
                    for(unsigned int i = fropPosition.getColonne() - 1
                    ; i > _arrivee.getColonne()
                    ; i--){
                            adapterSurface(fropPosition.getLigne(), i);

                    }
            }
            else if(fropPosition.getColonne() == _arrivee.getColonne()){
                
                if(fropPosition.getLigne() < _arrivee.getLigne())
                    for(unsigned int i = fropPosition.getLigne() + 1
                    ; i < _arrivee.getLigne()
                    ; i++){
                            adapterSurface(i, fropPosition.getColonne());

                    }
                if(fropPosition.getLigne() > _arrivee.getColonne())
                    for(unsigned int i = fropPosition.getLigne() - 1
                    ; i > _arrivee.getLigne()
                    ; i--){
                            adapterSurface(i, fropPosition.getColonne());

                    }

            }
            else{

                adapterSurface(fropPosition.getLigne(), _arrivee.getColonne());

                adapterSurface(_arrivee.getLigne(), fropPosition.getColonne());

                if(fropPosition.getLigne() < _arrivee.getLigne()  
                    && fropPosition.getColonne() < _arrivee.getColonne()){
                    for(unsigned int i = fropPosition.getLigne() + 1
                    ; i < _arrivee.getLigne()
                    ; i++){
                            adapterSurface(i, _arrivee.getColonne());

                            adapterSurface(i, fropPosition.getColonne());

                    }
                    for(unsigned int j = fropPosition.getColonne() + 1
                    ; j < _arrivee.getColonne()
                    ; j++){
                            adapterSurface(_arrivee.getLigne(), j);

                            adapterSurface(fropPosition.getLigne(), j);
                        
                    }
                }
                if(fropPosition.getLigne() < _arrivee.getLigne()
                    && fropPosition.getColonne() > _arrivee.getColonne()){
                    for(unsigned int i = fropPosition.getLigne() + 1
                    ; i < _arrivee.getLigne()
                    ; i++){
                            adapterSurface(i, _arrivee.getColonne());

                            adapterSurface(i, fropPosition.getColonne());

                    }
                    for(unsigned int j = fropPosition.getColonne() - 1
                    ; j > _arrivee.getColonne()
                    ; j--){
                            adapterSurface(_arrivee.getLigne(), j);

                            adapterSurface(fropPosition.getLigne(), j);
                        
                    }
                }

                if(fropPosition.getLigne() > _arrivee.getLigne()
                    && fropPosition.getColonne() < _arrivee.getColonne()){
                    for(unsigned int i = fropPosition.getLigne() - 1
                    ; i > _arrivee.getLigne()
                    ; i--){
                            adapterSurface(i, _arrivee.getColonne());

                            adapterSurface(i, fropPosition.getColonne());

                    }
                    for(unsigned int j = fropPosition.getColonne() + 1
                    ; j < _arrivee.getColonne()
                    ; j++){
                        
                            adapterSurface(_arrivee.getLigne(), j);

                            adapterSurface(fropPosition.getLigne(), j);

                    }
                }
                if(fropPosition.getLigne() > _arrivee.getLigne()
                    && fropPosition.getColonne() > _arrivee.getColonne()){
                    for(unsigned int i = fropPosition.getLigne() - 1
                    ; i > _arrivee.getLigne()
                    ; i--){
                            adapterSurface(i, _arrivee.getColonne());

                            adapterSurface(i,fropPosition.getColonne());

                    }
                    for(unsigned int j = fropPosition.getColonne() - 1
                    ; j > _arrivee.getColonne()
                    ; j--){                            
                            adapterSurface(_arrivee.getLigne(), j);

                            adapterSurface(fropPosition.getLigne(), j);

                    }

                }
            }
        }

        void Grill::adapterSurface(const unsigned int& ligne, const unsigned int& colonne){
            Surface& surfFrop = _terrain[ligne * _taille + colonne];

            long random = rand() % 5 + 2;

            if(surfFrop.getStrategy().nomStrategy() == "Eau" 
                && surfFrop.getEtat().nomEtat() == "Inexistant"
                && surfFrop.getStrategy().nomStrategy() != "Immortel")
                
            surfFrop.generateNenuphar(
                nenuphar::FactoryStrategyNenuphar::getStrategy(
                    static_cast<Surface::TypeNenu>(random)
                )
            );
        }
        
    }
}


