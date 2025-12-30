//
// Created by Rodrigo on 31/10/2025.
//

#include "Roseira.h"
#include "../Solo.h"
#include "../Settings.h"
#include "../Jardim.h"
#include <vector>
#include <algorithm>
#include <cstdlib>

Roseira:: Roseira(): Planta('r', "Roseira",10, Settings::Roseira::inicial_agua,Settings::Roseira::inicial_nutrientes, Beleza::BONITA) {

}

void Roseira::avancaInstante(Solo* solo, Jardim* jardim, int l, int c) {
    this->agua -= Settings::Roseira::perda_agua;
    this->nutrientes -= Settings::Roseira::perda_nutrientes;

    int aguaDoSolo = solo ->getAgua();
    int nutriDoSolo = solo->getNutrientes();

    int absorverAgua = std::min(aguaDoSolo, (int)Settings::Roseira::absorcao_agua);
    int absorverNutri = std::min(nutriDoSolo, (int)Settings::Roseira::absorcao_nutrientes);

    // Atualiza a planta
    this->agua += absorverAgua;
    this->nutrientes += absorverNutri;

    // Atualiza o solo
    solo->setAgua(aguaDoSolo - absorverAgua);
    solo->setNutrientes(nutriDoSolo - absorverNutri);

    std::vector<std::pair<int, int>> vizinhosLivres;
    int vizinhosOcupados = 0;
    int totalVizinhosValidos = 0;

    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0 && j==0) continue;

            int nL = l+i;
            int nC = c+j;

            if(nL >= 0 && nL < jardim->getLinhas() && nC >= 0 && nC < jardim ->getColunas()){
                totalVizinhosValidos++;
                Solo* vizinho = jardim->getSolo(nL, nC);

                if(vizinho->getPlanta() != nullptr){
                    vizinhosOcupados++;
                }else{
                    vizinhosLivres.push_back({nL,nC});
                }
            }
        }
    }

    bool morreu = false;
    if (this->agua <= 0 || 
        this->nutrientes <= 0 || 
        this->nutrientes >= Settings::Roseira::morre_nutrientes_maior ||
        (vizinhosOcupados == totalVizinhosValidos && totalVizinhosValidos > 0)) {
        morreu = true;
    }

    if (morreu) {
        this->saude = 0;
        solo->setAgua(solo->getAgua() + (this->agua / 2)); 
        solo->setNutrientes(solo->getNutrientes() + (this->nutrientes / 2));
        return; 
    }

    if (this->nutrientes > Settings::Roseira::multiplica_nutrientes_maior && !vizinhosLivres.empty()) {
        int index = rand() % vizinhosLivres.size();
        std::pair<int, int> pos = vizinhosLivres[index];
        
        Solo* soloFilho = jardim->getSolo(pos.first, pos.second);
        Roseira* novaRoseira = new Roseira();

        int metadeAgua = this->agua / 2;
        
        this->nutrientes = Settings::Roseira::original_nutrientes;
        this->agua = metadeAgua;

        novaRoseira->agua = metadeAgua;

        soloFilho->setPlanta(novaRoseira);
    }
}
