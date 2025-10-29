//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_JARDIM_H
#define TRABALHO_PRATICO_JARDIM_H

#include "Solo.h"

class Jardim {
    int linhas, colunas;
    Solo **area_solo;

public:
    Jardim(int lin, int col);
    ~Jardim(); //destrutor

    void printJardim() const;
};


#endif //TRABALHO_PRATICO_JARDIM_H