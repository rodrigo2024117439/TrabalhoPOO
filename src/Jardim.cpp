//
// Created by Rodrigo on 23/10/2025.
//

#include "Jardim.h"
#include <iostream>

Jardim::Jardim(int lin, int col): linhas(lin), colunas (col) { //construtor

    area_solo= new Solo*[lin];
    for (int i = 0; i < lin; i++) {
        area_solo[i]=new Solo[col];
    }
}

Jardim::~Jardim() { //destrutor
    for (int i = 0; i < linhas; ++i)
        delete[] area_solo[i];   // apaga cada linha
    delete[] area_solo;          // apaga o array de ponteiros
}

void Jardim::printJardim() const {
    std::cout << "\n   ";

    for (int c = 0; c < colunas; c++)
        std::cout << static_cast<char>('A' + c) << " ";
    std::cout << "\n";

    for (int l = 0; l < linhas; l++) {
        std::cout << " " << static_cast<char>('A' + l) << " ";
        for (int c = 0; c < colunas; ++c)
            std::cout << area_solo[l][c].getSimbolo() << " ";
        std::cout << "\n";
    }
}



