//
// Created by Rodrigo on 15/11/2025.
//

#include "ComandoLPlantaEsp.h"
#include "../../Solo.h"
#include "../../Plantas/Planta.h"
#include "../../Jardim.h"
#include <iostream>
#include <string>
#include <cctype>

void ComandoLPlantaEsp::executa(Jardim *jardim, const std::vector<std::string> &args) {

    if (args.size()!= 1) {
        std::cout<<"ERRO: este comando só aceito como arguemnto a localizacao";
        return;
    }
     const std::string& posicao = args[0];
    if (posicao.length() !=2 || !isalpha(posicao[0]) || !isalpha(posicao[1])) {
        std::cout<<"ERRO: Posicao errada ";
        return;
    }

    int index_linha= tolower(posicao[0]) - 'a';
    int index_coluna= tolower(posicao[1]) - 'a';

    if (index_linha < 0 || index_linha>= jardim->getLinhas() || index_coluna < 0 || index_coluna>= jardim->getColunas() ) {
        std::cout<<"ERRO: Tem que ser uma posicao no jardim";
        return;
    }

    Solo *solo=  jardim->getSolo(index_linha, index_coluna);

    if (!solo->getPlanta()) {
        std::cout<<"ERRO: Nao existe planta nessa localizacao";
        return;
    }

    Planta *planta= solo->getPlanta();
    std::cout<<"Detalhes da Planta:";
    std::cout<< "Especie: "<<planta->getEspecie()<<"\n";
    std::cout<<"Agua: "<<planta->getAgua()<<"\n";
    std::cout<<"Nutrientes: "<<planta->getNutrientes()<<"\n";
    std::cout<<"Saude: "<<planta->getSaude()<<"\n";



}
