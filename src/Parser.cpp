//
// Created by Rodrigo on 23/10/2025.
//

#include "Parser.h"
#include <sstream>

#include "Jardim.h"


Parser::Parser(const std::string &linha) : texto(linha) {
    std::istringstream iss(linha);
    std::string p;
    while (iss >> p)
        partes.push_back(p);
}

std::string Parser::getNome() const {
    if (partes.empty()) return "";
    return partes[0];
}

std::vector<std::string> Parser::getArgs() const {
    if (partes.size() <= 1) return {};

    return std::vector<std::string>(partes.begin() + 1, partes.end());
}

int Parser::getNumArgs() const {
    return partes.size() - 1;
}