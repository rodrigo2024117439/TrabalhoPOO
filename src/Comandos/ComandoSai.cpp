//
// Created by Rodrigo on 14/11/2025.
//

#include "ComandoSai.h"
#include "../Jardim.h"
#include "../Jardineiro.h"

void executa(Jardim *jardim, const std::vector<std::string>&args) {

    if (args.size()!= 0) {
        std::cout<<"ERRO: Este comando nao aceita argumentos \n";
    }

    Jardineiro *jardineiro = jardim -> getJardineiro();

    if (!jardineiro->estaNoJardim()) {
        std::cout<<"ERRO: o jardineiro nao esta noo jardim";
        return;
    }

    if (!jardineiro->podeEntrarSair()) {
        std::cout<<"ERRO: Ja foi usada a acao de entrar ou sair neste turno";
        return;
    }

    jardineiro->setNoJardim(false);
    jardineiro->entrarSair();

    std::cout<<"o jardineiro saiu do jardim\n";

    jardim->printJardim();
}