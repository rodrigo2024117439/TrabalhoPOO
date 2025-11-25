#include "ComandoLarga.h"
#include "../../Jardim.h"
#include "../../Jardineiro.h"
#include <iostream>

void ComandoLarga::executa(Jardim *jardim, const std::vector<std::string>& args) {
    if (!args.empty()) {
        std::cout << "Aviso: Este comando nao aceita argumentos (ignorado).\n";
    }

    jardim->getJardineiro()->desequiparFerramenta();
    std::cout << "Ferramenta guardada na mochila. Agora estas de maos vazias.\n";
}