#include <iostream>
#include "ErvaDaninha.h"
#include "../Solo.h"
#include "../Settings.h"
#include "../Jardim.h"
#include <vector>
#include <cstdlib>

ErvaDaninha::ErvaDaninha() 
    : Planta('e', "Erva Daninha", 10, Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, Beleza::FEIA) {
    instDeVida = 0;
    instParaMultiplicar = 0;
}

void ErvaDaninha::avancaInstante(Solo* solo, Jardim* jardim, int l, int c) {
    instDeVida++;
    if (instDeVida >= Settings::ErvaDaninha::morre_instantes) {
        this->saude = 0;
        return;
    }

    if (solo->getAgua() > 0) {
        solo->setAgua(solo->getAgua() - Settings::ErvaDaninha::absorcao_agua);
        this->agua += Settings::ErvaDaninha::absorcao_agua;
    }
    if (solo->getNutrientes() > 0) {
        solo->setNutrientes(solo->getNutrientes() - Settings::ErvaDaninha::absorcao_nutrientes);
        this->nutrientes += Settings::ErvaDaninha::absorcao_nutrientes;
    }

    instParaMultiplicar++;
    
    if (this->nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior && 
        instParaMultiplicar >= Settings::ErvaDaninha::multiplica_instantes) {

        std::vector<std::pair<int, int>> vizinhos;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int nL = l + i;
                int nC = c + j;

                if (nL >= 0 && nL < jardim->getLinhas() && nC >= 0 && nC < jardim->getColunas()) {
                    vizinhos.push_back({nL, nC});
                }
            }
        }

        if (!vizinhos.empty()) {
            int idx = rand() % vizinhos.size();
            Solo* soloAlvo = jardim->getSolo(vizinhos[idx].first, vizinhos[idx].second);
            
            if (soloAlvo->getPlanta() != nullptr) {
                std::cout << ">>> Erva Daninha matou a planta em " 
                          << static_cast<char>('A' + vizinhos[idx].first) 
                          << static_cast<char>('A' + vizinhos[idx].second) << "!\n";
            }
            soloAlvo->setPlanta(new ErvaDaninha());
            
            instParaMultiplicar = 0;
        }
    }
}