//
// Created by Rodrigo on 23/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Jardim::Jardim(int lin, int col): linhas(lin), colunas (col) {
    static bool seed_set = false;
    if (!seed_set) {
        srand(time(nullptr));
        seed_set = true;
    }

    area_solo = new Solo*[lin];
    for (int i = 0; i < lin; i++) {
        area_solo[i] = new Solo[col];
    }

    meuJardineiro = new Jardineiro();
}

Jardim::~Jardim() {
    for (int i = 0; i < linhas; ++i)
        delete[] area_solo[i];
    delete[] area_solo;

    delete meuJardineiro;
}

void Jardim::printJardim() const {
    std::cout << "\n   ";
    for (int c = 0; c < colunas; c++)
        std::cout << static_cast<char>('A' + c) << " ";
    std::cout << "\n";

    for (int l = 0; l < linhas; l++) {
        std::cout << " " << static_cast<char>('A' + l) << " ";
        for (int c = 0; c < colunas; ++c) {
            if (meuJardineiro->estaNoJardim() &&
                meuJardineiro->getLin() == l &&
                meuJardineiro->getCol() == c)
            {
                std::cout << meuJardineiro->getSimbolo() << " ";
            } else {
                std::cout << area_solo[l][c].getSimbolo() << " ";
            }
        }
        std::cout << "\n";
    }
}



