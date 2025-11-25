#include "PlantaExotica.h"
#include "../Solo.h"
#include "../Jardim.h"
#include <vector>
#include <algorithm>

PlantaExotica::PlantaExotica() 
    : Planta('x', "Planta Bomba", 50, 50, 50) { 
}

void PlantaExotica::avancaInstante(Solo *solo, Jardim* jardim, int l, int c) {
    
    this->agua -= 2;
    this->nutrientes -= 2;

    int aguaDoSolo = solo->getAgua();
    int nutriDoSolo = solo->getNutrientes();

    int absorverAgua = std::min(aguaDoSolo, 10);
    int absorverNutri = std::min(nutriDoSolo, 10);

    this->agua += absorverAgua;
    this->nutrientes += absorverNutri;

    solo->setAgua(aguaDoSolo - absorverAgua);
    solo->setNutrientes(nutriDoSolo - absorverNutri);

    if (this->nutrientes >= 300) {
        //REBENTA
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;

                int nL = l + i;
                int nC = c + j;

                // Verifica limites do jardim
                if (nL >= 0 && nL < jardim->getLinhas() && nC >= 0 && nC < jardim->getColunas()) {
                    Solo* vizinho = jardim->getSolo(nL, nC);
                    
                    // Adiciona 50 nutrientes a cada vizinho
                    vizinho->setNutrientes(vizinho->getNutrientes() + 50);
                }
            }
        }

        // A planta morre na explosão
        this->saude = 0;
        this->agua = 0;
        this->nutrientes = 0; 
        return; 
    }

    if (this->agua <= 0 || this->nutrientes <= 0) {
        this->saude = 0;
        solo->setNutrientes(solo->getNutrientes() + 10);
    }
}