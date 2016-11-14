#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <map>

#include "SurfEtat.hpp"
#include "StrategyNenuphar.hpp"
#include "FropEtat.hpp"
#include "Petit.hpp"
#include "Moyen.hpp"
#include "Grand.hpp"
#include "Inexistant.hpp"
#include "NenuVieillissant.hpp"
#include "NenuNonVieillissant.hpp"
#include "FactoryStrategyNenuphar.hpp"

namespace froppieLand{
    namespace modele{

        class Grill;

        namespace nenuphar{

            class Froppie;

            /**
             * Classe Abstraite définissant une surface (Surface ou eau)
             */
            class Surface{

            public:
                /**
                 * Définition de la grille comme classe Amie pour modifier la taille et la stratégie d'une Surface
                 */
                friend class Grill;

            public:
                /**
                 * Une Stratégie correspond au type de surface (Eau ou Nénuphar avec type)
                 */
                typedef FactoryStrategyNenuphar::TypeNenu TypeNenu;

                /**
                 * Constructeur de Surface
                 */
                Surface(unsigned int iS
                , unsigned int jS
                , const unsigned int& dimension);

                /**
                 * Destructeur de Surface
                 */
                ~Surface();

            public:
                /**
                 * Getter de la taille de la Surface
                 * @return Taille courante
                 */
                const SurfEtat& getEtat()const;
                
                /**
                 * Getter de la ligne pour la position de la Surface
                 * @return Numéro de ligne
                 */
                const unsigned int& getLigne()const;
                /**
                 * Getter de la colonne pour la position de la Surface
                 * @return Numéro de colonne
                 */
                const unsigned int& getColonne()const;
                /**
                 * Getter des cellules adjacentes
                 * @return Map des cellules adjacentes
                 */
                const std::map < Position, Direction const* >& getVoisinnage()const;
                /**
                 * Setter de la Stratégie (Type) de la Surface
                 */
                void setStrategy(StrategyNenuphar const* strategyNenuphar);

            public:
                /**
                 * Getter de la Stratégie (ou Type) de la Surface
                 * @return La stratégie
                 */
                const StrategyNenuphar& getStrategy()const;

                /**
                 * Getter de la de l'age (donc de la taille) de la surface
                 */
                void age(); //fait viellir le nenuphar
                
                /**
                 * Genère une Surface (état passé à Grand) et assigne la strategie (ou type) passée en paramètre
                 */
                void generateNenuphar(StrategyNenuphar const* strategyNenuphar);
                
                /**
                 * Inflige des dégats à Froppie
                 */
                void souffrir(froppie::Froppie& victim)const;

                /**
                 * Fonction booléenne déterminant l'adjacence d'une case
                 * @return Case Adjacente ?
                 */
                bool isCaseVoisine(const unsigned int& ligne, const unsigned int& colonne)const;
                
                /**
                 * Retrouve un vecteur direction en fonction de la case cible
                 * @return le vecteur Direction
                 */
                Direction const* getDirectionVoisin(const unsigned int& ligne, const unsigned int& colonne);


            protected:
                
                /**
                 * Action de viellissement d'une surface
                 */
                void vieillirEtat();

                /**
                 * Génération de la map des voisins
                 * @return Map des cellules adjacentes
                 */
                std::map < Position, Direction const* > genererMapVoisins(const unsigned int& dimension)const;
                
                /**
                 * Modification de l'état de la surface
                 */
                void setEtat(SurfEtat const* nEtat);

                /**
                 * Viellissement de la surface en fonction de l'état courant
                 */
                friend void Petit::age(Surface& victim)const;
                
                /**
                 * Viellissement de la surface en fonction de l'état courant
                 */
                friend void Moyen::age(Surface& victim)const;
                
                /**
                 * Viellissement de la surface en fonction de l'état courant
                 */
                friend void Grand::age(Surface& victim)const;
                
                /**
                 * Viellissement de la surface en fonction de l'état courant
                 */
                friend void Inexistant::age(Surface& victim)const;

                /**
                 * Viellissement de la surface en fonction du type de nénuphar courant
                 */
                friend void NenuVieillissant::vieillir(Surface& victim)const;
                
                /**
                 * Viellissement de la surface en fonction du type de nénuphar courant
                 */
                friend void NenuNonVieillissant::vieillir(Surface& victim)const;
                
            protected:

                /**
                 * Position de la surface
                 */
                const Position _sPosition;

                /**
                 * Taille de la surface
                 */
                SurfEtat const* _etat;

                /**
                 * Type de nénuphar avec sa stratégie d'action
                 */
                StrategyNenuphar const* _strategy;

                /**
                 * Map des positions de surfaces adjacentes
                 */
                std::map < Position, Direction const* > _voisins;

            };
        }
    }
}

#endif /* SURFACE_HPP */
