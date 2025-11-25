//
// Created by Rodrigo on 15/11/2025.
//

#include "ComandoLArea.h"
#include "../Jardim.h"
#include "../Solo.h"
#include "../Plantas/Planta.h"
#include "../Ferramentas/Ferramenta.h"
#include <iostream>

void ComandoLArea::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.size() != 0) {
        std::cout << "Este comandos nao aceita argumentos";
        return;
    }


    int n_solosNaoVazios = 0;

    for (int i = 0; i < jardim->getLinhas(); i++) {
        for (int j = 0; j < jardim->getColunas(); j++) {
            Solo *solo = jardim->getSolo(i, j);
            Planta *planta = solo->getPlanta();
            Ferramenta *ferramenta = solo->getFerramenta();

            if (planta != nullptr || ferramenta != nullptr) {
                n_solosNaoVazios++;

                char letra_linha = i + 'a';
                char letra_coluna = j + 'a';

                std::cout << " Posicao: " << letra_linha << " | " << letra_coluna << "\n";
                std::cout << "--Solo-- \n";
                std::cout << "Agua: " << solo->getAgua()<<"\n";
                std::cout << "Nutrientes: " << solo->getNutrientes()<<"\n";

                if (planta != nullptr) {
                    std::cout << "Contem a planta: " << planta->getEspecie()<<"\n";
                }
                if (ferramenta != nullptr) {
                    std::cout << "Conten a ferramenta: " << ferramenta->getTipo()<<"\n";
                }
            }
        }
    }

    if (n_solosNaoVazios == 0) {
        std::cout << "O jardim nao tem plantas nem ferramentas\n";
    }
}
