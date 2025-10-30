//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_JARDIM_H
#define TRABALHO_PRATICO_JARDIM_H

#include "Jardineiro.h"
#include "Solo.h"

class Jardim {
    int linhas, colunas;
    Solo **area_solo;
    Jardineiro* meuJardineiro;

public:
    Jardim(int lin, int col);
    ~Jardim(); //destrutor
    void printJardim() const;


    int getLinhas() const{ return linhas; }
    int getColunas() const{ return colunas; }
    Jardineiro* getJardineiro() const { return meuJardineiro; }
};
#endif //TRABALHO_PRATICO_JARDIM_H