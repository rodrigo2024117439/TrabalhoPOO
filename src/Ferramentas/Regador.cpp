//
// Created by diogo on 30/10/2025.
//
#include "Regador.h"
#include "../Jardineiro.h"
#include "../Solo.h"
#include <iostream>

Regador::Regador() : Ferramenta('g', "Regador"),
                     aguaRestante(Settings::Regador::capacidade) {
}

// Meta 2
bool Regador::avancaInstante(Jardineiro* jardineiro, Solo* solo) {
    solo->setAgua(solo->getAgua() + Settings::Regador::dose);
    this->aguaRestante -= Settings::Regador::dose;

    std::cout << "Regador usado! Agua restante: " << this->aguaRestante << "\n";

    if (this->aguaRestante <= 0) {
        std::cout << "O regador acabou e foi atirado para longe!\n";
        return true;
    }
    return false;
}