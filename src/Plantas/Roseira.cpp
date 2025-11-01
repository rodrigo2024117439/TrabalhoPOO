//
// Created by Rodrigo on 31/10/2025.
//

#include "Roseira.h"

#include "../Settings.h"


Roseira:: Roseira(): Planta('r', "Roseira",0, Settings::Roseira::inicial_agua,Settings::Roseira::inicial_nutrientes) {

}

void Roseira:: avancaInstante(Solo* solo) {}