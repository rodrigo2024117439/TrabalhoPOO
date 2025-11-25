//
// Created by Rodrigo on 23/10/2025.
//

#include "Solo.h"
#include "Plantas/Planta.h"
#include "Ferramentas/Ferramenta.h"
#include "Settings.h"
#include <cstdlib>
#include <ctime>

Solo::Solo() : planta(nullptr), ferramenta(nullptr) {
    agua = rand() % (Settings::Jardim::agua_max - Settings::Jardim::agua_min + 1) + Settings::Jardim::agua_min;
    nutrientes = rand() % (Settings::Jardim::nutrientes_max - Settings::Jardim::nutrientes_min + 1) + Settings::Jardim::nutrientes_min;
}

Solo::~Solo() {
    delete planta;
    delete ferramenta;
}

char Solo::getSimbolo() const {
    if (planta != nullptr)
        return planta->getSimbolo();
    if (ferramenta != nullptr)
        return ferramenta->getSimbolo();
    return ' ';
}

void Solo::setPlanta(Planta* p) {
    delete planta;
    planta = p;
}

void Solo::setFerramenta(Ferramenta* f) {
    delete ferramenta;
    ferramenta = f;
}

void Solo::setAgua(int novoValor) {
    agua = (novoValor < 0) ? 0: novoValor;
}

void Solo::setNutrientes(int novoValor) {
    nutrientes = (novoValor < 0) ? 0: novoValor;
}

Ferramenta* Solo::retirarFerramenta() {
    Ferramenta* temp = this->ferramenta; // Guarda o ponteiro temporariamente
    this->ferramenta = nullptr;          // Desliga o solo da ferramenta (sem apagar!)
    return temp;                         // Devolve a ferramenta "viva"
}
