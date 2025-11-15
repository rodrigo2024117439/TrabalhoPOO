//
// Created by Rodrigo on 15/11/2025.
//

#include "ComandoAvanca.h"
#include <iostream>
#include <string>
#include <vector>

void ComandoAvanca::executa(Jardim *jardim, const std::vector<std::string> &args) {
    int n_instantes = 1;

    if (args.size() > 1) {
        std::cout << "Este comando so aceita 1 arguemnto <numero de intantes>";
        return;
    }

    if (args.size() == 1) {
        try {
            const std::string numero = args[0];
            n_instantes = std::stoi(numero);
        }catch (std::invalid_argument) {
            std::cout << "ERRO: o argumento tem que ser um inteiro positivo";
            return;
        }
    }

    if (n_instantes < 1) {
        std::cout << "ERRO: O argumento tem que ser um interiro positivo";
    }

    std::cout<<"a simulacao avanciu " << n_instantes <<" instantes \n";





}
