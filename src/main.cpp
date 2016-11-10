#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Presentateur.hpp"

using namespace froppieLand::modele;

int main(int argc, char* argv[]){

    if(argc == 1){
        std::cout << "Fr0ppieLand : " << std::endl;
        std::cout << argv[0] << " resolution_minimal resolution_maximal resolution_base"
         << std::endl;
    
         return EXIT_SUCCESS;
    }

    if(argc != 4){

        std::cerr << "Nombre d'arguments invalide." << std::endl;
        std::cerr << "./Fr0ppieLand pour les infos de lancements." << std::endl;
    
        return EXIT_FAILURE;
    }

    //Début rétrieve de la résolution minimal
    int minimal;        //ici int pour pouvoir vérifier le paramètre positif
    {
        std::stringstream sInput(argv[1]);
        sInput >> minimal;
        
        if(!sInput  || !sInput.eof() || minimal < 2){
            std::cerr << "La valeur passée pour le paramètre resolution_minimal est invalide." << std::endl;
            std::cerr << "Celle-ci doit être supérieur à 1 et doit être entière." << std::endl;

            return EXIT_FAILURE;
        }
    }

    int maximal;
    {
        std::stringstream sInput(argv[2]);
        sInput >> maximal;

        if(!sInput || !sInput.eof() || maximal < minimal){
            std::cerr << "La valeur passée pour le paramètre resolution_maximal est invalide." << std::endl;
            std::cerr << "Celle-ci doit être supérieur à la valeur passée pour le paramètre resolution_minimal." << std::endl;
        
            return EXIT_FAILURE;
        }
    }

    int base;
    {
        std::stringstream sInput(argv[3]);
        sInput >> base;

        if(!sInput || !sInput.eof() || !( minimal <= base && base <= maximal )){
            std::cerr << "La valeur passée pour le paramètre resolution_base est invalide." << std::endl;
            std::cerr << "Celle-ci doit être comprise entre la valeur de resolution_minimal et de celle de resolution_maximal." << std::endl;
        
            return EXIT_FAILURE;
        }
    }

    //Glib::RefPtr < Gtk::Application > app = Gtk::Application::create(argc, argv, "froppie.land");
    Gtk::Main mainSystem(argc, argv);

    std::cout << "Initialisation de la fenètre..." << std::endl;

    froppieLand::vue::FroppieVue::initialiser();

    std::cout << "Initialisation du Presentateur..." << std::endl;
    froppieLand::presentateur::Presentateur pres(
        static_cast<unsigned int>(base)
        , static_cast<unsigned int>(base) - 1
        , 0u
        , 0u
        , static_cast<unsigned int>(base) - 1
        , static_cast<unsigned int>(minimal)
        , static_cast<unsigned int>(maximal)
        , 60u
        , 1u);


    std::cout << "C'est partie !" << std::endl;

    pres.demarer();

    return EXIT_SUCCESS;
}