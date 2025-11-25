#include "Tesoura.h"
#include "../Solo.h"
#include "../Plantas/Planta.h"
#include <iostream>

Tesoura::Tesoura() : Ferramenta('t', "Tesoura") {
}

bool Tesoura::avancaInstante(Jardineiro *jardineiro, Solo* solo) {
    Planta* planta = solo->getPlanta();

    if (planta != nullptr) {
        
        if (planta->getEspecie() == "Erva Daninha") {
            std::cout << "A tesoura cortou uma Erva Daninha!\n";
            solo->setPlanta(nullptr);
        }
    }
    return false;
}