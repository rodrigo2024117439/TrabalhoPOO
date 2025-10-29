//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_COMANDO_H
#define TRABALHO_PRATICO_COMANDO_H
#include <string>
#include <vector>

class Comando {
    std::string texto;
    std::vector<std::string> partes;

    public:
    explicit Comando(const std::string &linha);
    void validar();

};


#endif //TRABALHO_PRATICO_COMANDO_H