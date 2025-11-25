#include "Adubo.h"
#include "../Settings.h"
#include "../Solo.h"
#include <iostream>

Adubo::Adubo() : Ferramenta('a', "Saco de Adubo") {
    usosRestantes = Settings::Adubo::capacidade; 
}

bool Adubo::avancaInstante(Jardineiro* jardineiro, Solo* solo) {
    solo->setNutrientes(solo->getNutrientes() + Settings::Adubo::dose);
    this->usosRestantes -= Settings::Adubo::dose;
    
    std::cout << "Adubo aplicado! Restam: " << this->usosRestantes << "\n";

    if (this->usosRestantes <= 0) {
        std::cout << "O saco de adubo acabou e o vento levou-o!\n";
        return true;
    }
    return false;
}