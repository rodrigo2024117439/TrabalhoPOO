#include "ComandoIFerr.h"
#include "../../Jardim.h"
#include "../../Jardineiro.h"
#include <iostream>

void ComandoIFerr::executa(Jardim *jardim, const std::vector<std::string>& args) {
    if (jardim->getJardineiro() == nullptr) return;

    std::cout << jardim->getJardineiro()->getInventarioString();
}
