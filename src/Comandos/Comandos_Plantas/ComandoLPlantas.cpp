//
// Created by Rodrigo on 14/11/2025.
//

#include "ComandoLPlantas.h"

#include <iostream>
#include "../../Jardim.h"
#include "../../Jardineiro.h"
#include "../../Plantas/Planta.h"
#include "../../Solo.h"

void ComandoLPlantas::executa(Jardim *jardim, const std::vector<std::string>& args) {

    if (args.size()!=0) {
        std::cout<<"Este comando nao aceita argumentos\n";
        return;
    }

    std::cout<<"Plantas existentes:\n";
    int plantasEncontradas=0;

    for (int i=0; i<jardim->getLinhas(); i++) {
        for (int j=0; j<jardim->getColunas();j++) {

            Solo *solo=jardim->getSolo(i,j);
            Planta *planta=solo->getPlanta();

            if (planta != nullptr) {
                plantasEncontradas++;

                char linhaLetra= 'a' + i;
                char colunaLetra= 'a' + j;

                std::cout<<"Planta: "<<planta->getEspecie()<<" na posicao: "<<linhaLetra <<colunaLetra<<";\n";
                std::cout<<"Saude: "<<planta->getSaude()<<" ";
                std::cout<<"Agua: "<<planta->getAgua()<<" ;";
                std::cout<<"Nutrientes: "<<planta->getNutrientes()<<" ;";
                std::cout<<"\n";
                std::cout<<"Solo: ";
                std::cout<<"Agua: "<<solo->getAgua()<<" ;";
                std::cout<<"Nutrientes: " <<solo->getNutrientes()<<" ;\n";
            }
        }
    }

    if (plantasEncontradas==0) {
        std::cout<<"Nao existem plantas no jardim\n";
    }
}
