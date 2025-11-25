//
// Created by Rodrigo on 14/11/2025.
//

#include "ComandoBaixo.h"
#include <iostream>
#include "../../Jardim.h"
#include "../../Jardineiro.h"


void ComandoBaixo::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.size() != 0) {
        std::cout << "ERO:este comando nao aceita argumentos";
        return;
    }
    Jardineiro *jardineiro = jardim->getJardineiro();

    if (!jardineiro->estaNoJardim()) {
        std::cout<<"ERRO: Jardineiro nao esta no jardim";
        return;
    }

    if (!jardineiro->podeMover()) {
        std::cout<<"ERRO: Jardineiro nao pode mover mais";
        return;
    }

    int linhaAtual=jardineiro->getLin();
    int novaLinha=linhaAtual+1;

    if (novaLinha>=jardim->getLinhas()) {
        std::cout<<"ERRO: Limite do jardim atingido";
        return;
    }

    jardineiro->setPos(novaLinha, jardineiro->getCol());
    jardineiro->mover();
    jardim->verificarFerramentasNoChao();

    jardim->printJardim();
}
