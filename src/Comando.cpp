//
// Created by Rodrigo on 23/10/2025.
//

#include "Comando.h"
#include <iostream>
#include <sstream>

#include "Jardim.h"


Comando::Comando(const std::string &linha) : texto(linha) {
    std::istringstream iss(linha);
    std::string p;
    while (iss >> p)
        partes.push_back(p);
}

// Implementação das novas funções "get"
std::string Comando::getNome() const {
    if (partes.empty()) return "";
    return partes[0];
}

std::vector<std::string> Comando::getArgs() const {
    if (partes.size() <= 1) return {};

    return std::vector<std::string>(partes.begin() + 1, partes.end());
}

int Comando::getNumArgs() const {
    return partes.size() - 1;
}