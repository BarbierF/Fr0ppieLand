#include <cmath>
#include <random>

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
                    _terrain.push_back(Surface(i, j));
                }
            }


            _terrain[ posLigneD * _taille + posColonneD ].generateNenuphar(
                nenuphar::FactoryStrategyNenuphar::getStrategy(Surface::TypeNenu::immortel)
            );

            _terrain[ posLigneA * _taille + posColonneA ].generateNenuphar(
                nenuphar::FactoryStrategyNenuphar::getStrategy(Surface::TypeNenu::immortel)
            );

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

            std::default_random_engine generateur;
            std::uniform_int_distribution<int> distribution(0, 7); //On va générer les nombres de 1 à 7.

            const Position& fropPosition = _froppie.getPosition();
            
            if(fropPosition.getLigne() == _arrivee.getLigne()){
                for(unsigned int i = 0 ; i < std::abs(_arrivee.getColonne() - fropPosition.getColonne()) ; i++){
                    
                    Surface& surfFrop = _terrain[fropPosition.getLigne() * _taille + i];

                    if(surfFrop.getStrategy().nomStrategy() == "Eau" && surfFrop.getEtat().nomEtat() == "Inexistant")   
                        surfFrop.generateNenuphar(
                            nenuphar::FactoryStrategyNenuphar::getStrategy(static_cast<Surface::TypeNenu>(distribution(generateur)))
                        );
                }
            }
            else if(fropPosition.getColonne() == _arrivee.getColonne()){
                for(unsigned int i = 0 ; i < std::abs(_arrivee.getLigne() - fropPosition.getColonne()) ; i++){

                    Surface& surfFrop = _terrain[i * _taille + fropPosition.getColonne()];

                    if(surfFrop.getStrategy().nomStrategy() == "Eau" && surfFrop.getEtat().nomEtat() == "Inexistant")
                    surfFrop.generateNenuphar(
                        nenuphar::FactoryStrategyNenuphar::getStrategy(static_cast<Surface::TypeNenu>(distribution(generateur)))
                    );
                }
            }
            else{
                for(unsigned int i = 0 ; i < std::abs(_arrivee.getLigne() - fropPosition.getLigne()) ; i++){
                    for(unsigned int j = 0 ; j < std::abs(_arrivee.getColonne() - fropPosition.getColonne()) ; j++){
                        
                        Surface& surfFrop = _terrain[i * _taille + j];

                        if(surfFrop.getStrategy().nomStrategy() == "Eau" && surfFrop.getEtat().nomEtat() == "Inexistant")
                        surfFrop.generateNenuphar(
                            nenuphar::FactoryStrategyNenuphar::getStrategy(static_cast<Surface::TypeNenu>(distribution(generateur)))
                        );
                    }
                }
            }
        }
        
    }
}


