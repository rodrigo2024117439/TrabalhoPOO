//
// Created by Rodrigo on 23/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Plantas/Planta.h"
#include "Ferramentas/Regador.h"
#include "Ferramentas/Adubo.h"
#include "Ferramentas/Tesoura.h"
#include "Ferramentas/FerramentaZ.h"

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
    
    for (int i = 0; i < 3; ++i) {
        spawnFerramentaAleatoria();
    }
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
    
    verificarFerramentasNoChao();

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            Solo *solo = getSolo(i, j);
            Planta *planta = solo->getPlanta();
            if (planta != nullptr && !planta->foiProcessadaEsteTurno()) {
                planta->avancaInstante(solo, this, i, j);
                planta->setProcessadaEsteTurno(true);

                if (planta->getSaude() <= 0) {
                    char letraLinha = 'A' + i;
                    char letraColuna = 'A' + j;
                    std::cout << "A planta " << planta->getEspecie() << " morreu na posicao " << letraLinha << letraColuna << "\n";
                    solo->setPlanta(nullptr);
                }
            }
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (getSolo(i,j)->getPlanta()) 
                getSolo(i,j)->getPlanta()->setProcessadaEsteTurno(false);
        }
    }

    if (meuJardineiro->estaNoJardim()) {
        int l = meuJardineiro->getLin();
        int c = meuJardineiro->getCol();
        Solo* soloAtual = getSolo(l, c);

        Ferramenta* ferramenta = meuJardineiro->getFerramentaNaMao();

        if (ferramenta != nullptr) {
            bool quebrou = ferramenta->avancaInstante(meuJardineiro, soloAtual);
            
            if (quebrou) {
                meuJardineiro->removerFerramentaPartida();
            }
        }
    }
    meuJardineiro->resetContadoresTurno();
}

void Jardim::spawnFerramentaAleatoria() {
    int maxTentativas = 100;
    int tentativas = 0;

    while (tentativas < maxTentativas) {
        int l = rand() % linhas;
        int c = rand() % colunas;
        Solo* solo = getSolo(l, c);

        if (solo->getFerramenta() == nullptr && solo->getPlanta() == nullptr) {
            
            int tipo = rand() % 4;
            Ferramenta* nova = nullptr;

            switch (tipo) {
                case 0: nova = new Regador(); break;
                case 1: nova = new Adubo(); break;
                case 2: nova = new Tesoura(); break;
                case 3: nova = new FerramentaZ(); break;
            }

            if (nova != nullptr) {
                solo->setFerramenta(nova);
                return;
            }
        }
        tentativas++;
    }
}

void Jardim::verificarFerramentasNoChao() {
    if (!meuJardineiro->estaNoJardim()) return;

    int l = meuJardineiro->getLin();
    int c = meuJardineiro->getCol();
    Solo* solo = getSolo(l, c);

    Ferramenta* f = solo->retirarFerramenta();

    if (f != nullptr) {
        if (meuJardineiro->adicionarFerramenta(f)) {
            solo->setFerramenta(nullptr);
            std::cout << ">>> Encontraste: " << f->getTipo() << "! Foi para a mochila.\n";
            
            spawnFerramentaAleatoria();
        } else {
            std::cout << ">>> Encontraste uma ferramenta, mas a mochila pode estar cheia.\n";
        }
    }
}

Jardim::Jardim(const Jardim &outro) {
    linhas = outro.linhas;
    colunas = outro.colunas;
    
    area_solo = new Solo*[linhas];
    for (int i = 0; i < linhas; i++) {
        area_solo[i] = new Solo[colunas];
        for (int j = 0; j < colunas; j++) {
            area_solo[i][j] = outro.area_solo[i][j]; 
            
            if (outro.area_solo[i][j].getPlanta() != nullptr) {
                area_solo[i][j].setPlanta(outro.area_solo[i][j].getPlanta()->duplicar());
            }
            
            if (outro.area_solo[i][j].getFerramenta() != nullptr) {
                area_solo[i][j].setFerramenta(outro.area_solo[i][j].getFerramenta()->duplicar());
            }
        }
    }

    // Copiar o Jardineiro
    meuJardineiro = new Jardineiro(*outro.meuJardineiro);
}