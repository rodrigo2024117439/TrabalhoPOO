//
// Created by Rodrigo on 31/10/2025.
//

#ifndef TRABALHO_PRATICO_ROSEIRA_H
#define TRABALHO_PRATICO_ROSEIRA_H

#include "Planta.h"

class Roseira : public Planta {
    int instSemAgua;
    int instSemNutrientes;
    int instComNutrientesAMais;

public:
    Roseira();

    void avancaInstante(Solo* solo) override;


};

#endif //TRABALHO_PRATICO_ROSEIRA_H