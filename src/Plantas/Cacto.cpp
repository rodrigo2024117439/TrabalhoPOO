#include "Cacto.h"
#include "../Solo.h"
#include "../Settings.h"
#include "../Jardim.h"
#include <algorithm>
#include <vector>


Cacto::Cacto() : Planta('c', "Cacto", 1, 0, 0), instantesComMuitaAgua(0), instantesSemNutrientes(0) {
}

void Cacto::morre(Solo* solo) {
    this -> saude = 0;

    int soloNutrientes = solo -> getNutrientes();
    solo->setNutrientes(soloNutrientes + this->nutrientes);

    this->nutrientes = 0;
    this->agua = 0;
}

// MEta 2
void Cacto::avancaInstante(Solo* solo, Jardim* jardim, int l, int c) {
    if (this->saude <= 0) {
        return;
    }

    int soloAgua = solo->getAgua();
    int soloNutrientes = solo->getNutrientes();

    //Especial do Cato------
    //absorve 25% das unidades de água
    int aguaAbsorvida = static_cast<int>(soloAgua * (Settings::Cacto::absorcao_agua_percentagem / 100.0));
    this->agua += aguaAbsorvida;
    solo->setAgua(soloAgua - aguaAbsorvida);

    //absorve até 5 unidades de nutrientes
    int nutrientesParaAbsorver = Settings::Cacto::absorcao_nutrientes;
    int nutrientesAbsorvidos = std::min(soloNutrientes, nutrientesParaAbsorver);
    this->nutrientes += nutrientesAbsorvidos;
    solo->setNutrientes(soloNutrientes - nutrientesAbsorvidos);

    //Morre se água > 100 por 3 instantes
    if (solo->getAgua() > Settings::Cacto::morre_agua_solo_maior) {
        instantesComMuitaAgua++;
        if (instantesComMuitaAgua > Settings::Cacto::morre_agua_solo_instantes) {
            morre(solo);
            return;
        }
    } else {
        instantesComMuitaAgua = 0;
    }

    //Morre se nutrientes no solo == 0 por 3 instantes
    if (solo->getNutrientes() < Settings::Cacto::morre_nutrientes_solo_menor) {
        instantesSemNutrientes++;
        if (instantesSemNutrientes > Settings::Cacto::morre_nutrientes_solo_instantes) {
            morre(solo);
            return;
        }
    } else {
        instantesSemNutrientes = 0;
    }

    if (this->nutrientes > Settings::Cacto::multiplica_nutrientes_maior && 
        this->agua > Settings::Cacto::multiplica_agua_maior) {

        std::vector<std::pair<int, int>> vizinhosLivres;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int nL = l + i;
                int nC = c + j;

                if (nL >= 0 && nL < jardim->getLinhas() && nC >= 0 && nC < jardim->getColunas()) {
                    if (jardim->getSolo(nL, nC)->getPlanta() == nullptr) {
                        vizinhosLivres.push_back({nL, nC});
                    }
                }
            }
        }

        if (!vizinhosLivres.empty()) {
            int idx = rand() % vizinhosLivres.size();
            Solo* soloFilho = jardim->getSolo(vizinhosLivres[idx].first, vizinhosLivres[idx].second);
            
            Cacto* filho = new Cacto();

            int metadeAgua = this->agua / 2;
            int metadeNutri = this->nutrientes / 2;

            this->agua = metadeAgua;
            this->nutrientes = metadeNutri;

            filho->agua = metadeAgua; 
            filho->nutrientes = metadeNutri;

            soloFilho->setPlanta(filho);
        }
    }
}