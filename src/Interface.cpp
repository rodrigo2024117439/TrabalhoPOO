//
// Created by Rodrigo on 23/10/2025.
//

#include "Interface.h"
#include <iostream>
#include "Comando.h"

void Interface::iniciar() {
    std::string linha;
    std::cout << "=== Simulador de Jardim ===\n";
    std::cout << "Comandos:\n";
    std::cout << "Escreva 'fim' para sair.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, linha);

        if (linha == "fim") {
            std::cout << "Programa terminado.\n";
            break;
        }

        Comando cmd(linha);
        cmd.validar();
    }
}
