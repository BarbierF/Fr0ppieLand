#ifndef SURFETAT_HPP
#define SURFETAT_HPP

#include <string>

namespace froppieLand{
    namespace modele{
        namespace nenuphar{
            class Surface;
            /**
             * Classe définissant l'age (et donc la taille) d'un nénuphar
             */
            class SurfEtat{
                public:
                    /**
                     * Méthode de vieillissement de la surface victime
                     * @param victim Cible du vieillissement
                     */
                    virtual void age(Surface& victim)const=0;
                    /**
                     * Nom de l'état courant (décrivant l'âge)
                     * @return le nom de l'état (donc la taille)
                     */
                    virtual const std::string nomEtat()const=0;
                };
        }
    }
}

#endif
