#include "ComandoPega.h"
#include "../../Jardim.h"
#include "../../Jardineiro.h"
#include <iostream>

void ComandoPega::executa(Jardim* jardim, const std::vector<std::string>& args) {
    if (args.size() != 1) {
        std::cout << "Erro: Use 'pega <numero_serie>'\n";
    }

    try {
        int id = std::stoi(args[0]);
        Jardineiro* j = jardim->getJardineiro();
        
        if (j->equiparFerramenta(id)) {
            std::cout << "Ferramenta " << id << " equipada!\n";
        } else {
            std::cout << "Nao foi possivel equipar a ferramenta " << id << ".\n";
        }
    } catch (...) {
        std::cout << "Erro: O argumento deve ser um numero.\n";
    }
}