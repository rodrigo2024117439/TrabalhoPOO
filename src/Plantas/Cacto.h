//
// Created by diogo on 30/10/2025.
//
#ifndef TRABALHO_PRATICO_CACTO_H
#define TRABALHO_PRATICO_CACTO_H

#include "Planta.h"
#include "../Settings.h"

class Cacto : public Planta {
    int instantesComMuitaAgua;
    int instantesSemNutrientes;

    void morre(Solo* solo);

public:
    Cacto();

    void avancaInstante(Solo* solo, Jardim* jardim, int l, int c) override;
    Planta* duplicar() const override { return new Cacto(*this); }
};

#endif