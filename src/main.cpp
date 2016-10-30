#include <iostream>
#include <cstdlib>

#include "modele/include/Grill.hpp"

using namespace froppieLand::modele;

int main(){
    std::cout << "Hello World" << std::endl;

    Grill* grill = new Grill(10, 0, 0, 9, 9);

    return EXIT_SUCCESS;
}