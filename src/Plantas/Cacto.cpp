#include "Cacto.h"
#include "../Solo.h"
#include "../Settings.h"
#include <algorithm>

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