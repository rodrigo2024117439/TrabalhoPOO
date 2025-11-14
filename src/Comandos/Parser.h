//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_COMANDO_H
#define TRABALHO_PRATICO_COMANDO_H
#include <string>
#include <vector>

class Parser {
    std::string texto;
    std::vector<std::string> partes;

public:
    explicit Parser(const std::string &linha);

    std::string getNome() const;

    std::vector<std::string> getArgs() const;

    int getNumArgs() const;
};


#endif //TRABALHO_PRATICO_COMANDO_H