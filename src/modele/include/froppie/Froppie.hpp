#ifndef FROPPIE_HPP
#define FROPPIE_HPP

#include "Position.hpp"
#include "Direction.hpp"
#include "Eau.hpp"
#include "Dopant.hpp"
#include "Mortel.hpp"
#include "Nutritif.hpp"
#include "Veneneux.hpp"

    namespace froppieLand{
        namespace modele{
            namespace froppie{
                
                class FropEtat;

                /**
                 * Classe décrivant Froppie
                 */
                class Froppie{

                public: 

                    /**
                     * Définition des amis pour modification ultérieure de Froppie
                     */
                    friend class Malade;
                    friend class Sain;
                    friend class Mort;

                    friend class nenuphar::Dopant;
                    friend class nenuphar::Eau;
                    friend class nenuphar::Mortel;
                    friend class nenuphar::Nutritif;
                    friend class nenuphar::Veneneux;
                    
                    typedef modele::Direction Direction;

                // ----- Gestion des composantes de Froppie -----
                public:
                    /**
                     * Constructeur de Froppie
                     */
                    Froppie(
                        const int pdv
                        , const unsigned int depLigne
                        , const unsigned int depColonne);
                    
                    /**
                     * Destructeur de Froppie
                     */
                    ~Froppie();

                    /**
                     * Suppression du constructeur par recopie
                     */
                    Froppie(const Froppie& ) = delete;

                    /**
                     * Suppression de l'opérateur d'affectation
                     */
                    Froppie& operator=(const Froppie& )const = delete; 

                public:

                    /**
                     * Getter des Points de vie
                     */
                    const int& getPDV()const;

                    /**
                     * Getter du nombre de mouvements
                     */
                    const unsigned int& getNbMove()const;

                    /**
                     * Getter de la position de Froppie
                     */
                    const Position& getPosition()const;

                    /**
                     * Getter de l'état courant de Froppie
                     */
                    const FropEtat& getEtat()const;
                
                // ----- Partie Gestion des Etats -----
                protected:

                    /**
                     * Changement de l'état de Froppie vers Sain
                     */
                    void setSain();

                    /**
                     * Changement de l'état de Froppie vers Malade
                     */
                    void setMalade();

                    /**
                     * Changement de l'état de Froppie vers Mort
                     */
                    void setMort();

                // ---- Gestion des Actions & Déplacement -----
                public:
                    
                    /**
                     * Déplacement de Froppie dans la direction donnée
                     * @param direction Vecteur de déplacement
                     * @return La position finale de Froppie
                     */
                    const Position& deplacer(const Direction& );                    

                protected:
                    
                    /**
                     * Action de perte des Points de vie
                     */
                    void subir();

                    /**
                     * Ajout de point de vie (Nenuphar boostant)
                     */
                    void doper();

                    /**
                     * Soin de Froppie
                     */
                    void soigner();


                protected: 

                    /**
                     * Nombre de points de vie
                     */
                    int _pointDeVie;

                    /**
                     * Nombre de mouvements effectués par Froppie
                     */
                    unsigned int _nbMove;

                    /**
                     * Position de Froppie
                     */
                    Position _position;

                    /**
                     * Etat courant de Froppie
                     */
                    FropEtat const* _etat;


                };
            }

            
        }
    }

#endif
