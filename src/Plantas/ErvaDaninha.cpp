//
// Created by Rodrigo on 31/10/2025.
//

#include "ErvaDaninha.h"
#include "../Settings.h"


ErvaDaninha::ErvaDaninha() : Planta('e', "Erva Daninha", 0, Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes) {

    instDeVida=0;
    instParaMultiplicar=0;
}

void ErvaDaninha::avancaInstante(Solo* solo) {}
