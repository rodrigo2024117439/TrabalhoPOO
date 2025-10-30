//
// Created by diogo on 30/10/2025.
//
#ifndef TRABALHO_PRATICO_CACTO_H
#define TRABALHO_PRATICO_CACTO_H

#include "Planta.h"
#include "Settings.h"

class Cacto : public Planta {
    int instantesComMuitaAgua;
    int instantesSemNutrientes;

public:
    Cacto();

    void avancaInstante(Solo* solo) override;
};

#endif