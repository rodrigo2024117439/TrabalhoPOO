//
// Created by Rodrigo on 14/11/2025.
//

#include "ComandoDir.h"
#include <iostream>
#include "../../Jardim.h"
#include "../../Jardineiro.h"

#include "ComandoEsq.h"

void ComandoDir::executa(Jardim *jardim, const std::vector<std::string> &args) {
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

    int ColAtual=jardineiro->getCol();
    int novaCol=ColAtual+1;

    if (novaCol >= jardim->getColunas()) {
        std::cout<<"ERRO: Limite do jardim atingido";
        return;
    }

    jardineiro->setPos(jardineiro->getLin(), novaCol);
    jardineiro->mover();
    jardim->verificarFerramentasNoChao();

    jardim->printJardim();
}