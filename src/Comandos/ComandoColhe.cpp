//
// Created by Rodrigo on 14/11/2025.
//

#include "ComandoColhe.h"
#include "../Solo.h"
#include "../Jardim.h"
#include <iostream>
#include <string>
#include <cctype>
#include "../Jardineiro.h"

void ComandoColhe::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.size()!= 1) {
        std::cout<<"ERRO: funcao so recebe o argumento de posicao \n";
        return;
    }

    std::string argumentos=args[0];

    if (argumentos.length()!=2 || !isalpha(argumentos[0]) || !isalpha(argumentos[1])) {
        std::cout<<"ERRO: posicao tem que ser 2 letras \n";
        return;
    }


    int linhaIndex= tolower(argumentos[0]) - 'a';
    int colunaIndex= tolower(argumentos[1]) - 'a';

    if (linhaIndex <0 || linhaIndex>= jardim->getLinhas() || colunaIndex <0 || colunaIndex >= jardim->getColunas()) {
        std::cout<<"ERRO: posicao invalida \n";
        return;
    }

    Jardineiro *jardineiro=jardim->getJardineiro();

    if (!jardineiro->podeColher()) {
        std::cout<<"ERRO: ja colheu 5 vezs \n";
        return;
    }

    Solo *solo=jardim->getSolo(linhaIndex, colunaIndex);

    if (solo->getPlanta()==nullptr) {
        std::cout<<"ERRO: Nao ha planta nestas coordenadas \n";
        return;
    }

    solo->setPlanta(nullptr);
    jardineiro->colher();

    std::cout<< "A planta na posicao "<< argumentos << " foi colhida \n";

    jardim->printJardim();

}
