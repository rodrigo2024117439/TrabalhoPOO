#include "Tesoura.h"
#include "../Solo.h"
#include "../Plantas/Planta.h"
#include <iostream>

Tesoura::Tesoura() : Ferramenta('t', "Tesoura") {
}

bool Tesoura::avancaInstante(Jardineiro *jardineiro, Solo* solo) {
    Planta* planta = solo->getPlanta();
    if (planta != nullptr && planta->getBeleza() == Beleza::FEIA) {
        std::cout << "A tesoura removeu uma planta feia (" << planta->getEspecie() << ").\n";
        solo->setPlanta(nullptr);
    }
    return false;
}