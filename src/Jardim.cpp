//
// Created by Rodrigo on 23/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include <ctime>
#include "Plantas/Planta.h"

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

Solo *Jardim::getSolo(int lin, int col) const {
    if (lin >= 0 && lin < linhas && col >= 0 && col < colunas) {
        return &area_solo[lin][col];
    }
    return nullptr;
}



void Jardim::avancaUMinstante() {
    for (int i=0; i< linhas; i++) {
        for (int j=0; j< colunas; j++) {
            Solo *solo = getSolo(i,j);
            Planta *planta=solo->getPlanta();
            if (planta != nullptr) {
                planta->avancaInstante(solo, this, i, j);

                if (planta->getSaude() <= 0) {
                    char letraLinha = 'a' + i;
                    char letraColuna = 'a' + j;

                    std::cout << "A planta " << planta->getEspecie() << " morreu na posicao " << letraLinha << letraColuna << "\n";
                    solo->setPlanta(nullptr);
                }
            }
        }
    }

    if (meuJardineiro->estaNoJardim()) {
        //logica para as ferramentas, mas quero primeiro fazer os outros codigos para elas
    }
    meuJardineiro->resetContadoresTurno();
}

