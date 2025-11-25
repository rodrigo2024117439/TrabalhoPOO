#include "FerramentaZ.h"
#include "../Solo.h"
#include "../Plantas/Planta.h"
#include <iostream>

Triturador::Triturador() : Ferramenta('z', "Triturador Organico"), usosRestantes(5) {
}

bool Triturador::avancaInstante(Jardineiro* jardineiro, Solo* solo) {
    Planta* planta = solo->getPlanta();

    if (planta != nullptr) {

        int aduboGerado = planta->getSaude() * 2;
        
        aduboGerado += (planta->getNutrientes() / 2);

        int nutrientesAtuais = solo->getNutrientes();
        solo->setNutrientes(nutrientesAtuais + aduboGerado);

        solo->setPlanta(nullptr); 

        usosRestantes--;
        
        std::cout << "Planta triturada, gerou " << aduboGerado 
                  << " nutrientes extra. (Restam " << usosRestantes << " usos)\n";
    } else {
        std::cout << "Nao ha planta aqui para triturar.\n";
    }

    if (usosRestantes <= 0) {
        std::cout << "A ferramenta partiu-se!\n";
        return true;
    }

    return false;
}