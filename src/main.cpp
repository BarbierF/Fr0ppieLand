#include <iostream>
#include <cstdlib>

#include "include/Grill.hpp"

int main(){
    std::cout << "Hello World" << std::endl;

    Grill* grill = new Grill(10, 0, 0, 9, 9);

    system("PAUSE");
    return EXIT_SUCCESS;
}