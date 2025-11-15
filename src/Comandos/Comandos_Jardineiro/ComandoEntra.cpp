//
// Created by Rodrigo on 14/11/2025.
//

#include "ComandoEntra.h"
#include "../../Jardineiro.h"
#include "../../Jardim.h"
#include <iostream>
#include <string>
#include <cctype>


void ComandoEntra::executa(Jardim *jardim, const std::vector<std::string> &args) {


if (args.size() != 1) {
    std::cout<< "Erro: nº de argumentos invalido \n";
    return;
    }
    std::string argumento= args[0];
    if ( argumento.length()!=2 || !isalpha(argumento[0]) || !isalpha(argumento[1])) {
        std::cout << "ERRO: Argumento invalido (so se pode usar 2 letras)\n";
        return;
    }
    char argumento_linhas= argumento[0];
    char argumento_colunas= argumento[1];
    int index_linha = argumento_linhas-'a';
    int index_colunas = argumento_colunas-'a';


    if (index_linha < 0 || index_linha >= jardim->getLinhas() || index_colunas < 0 || index_colunas >= jardim->getColunas()) {
        std::cout << "ERRO- Numero de linhas ou colunas invalido\n";
        return;
    }

    Jardineiro* jardineiro= jardim->getJardineiro();
    if (!jardineiro->podeEntrarSair()) {
        std::cout << "ERRO- Ja usou a sua acao de entrar/sair neste turno.\n";
        return;
    }

    jardineiro->setPos(index_linha, index_colunas);
    jardineiro->setNoJardim(true);
    jardineiro->entrarSair();

    std::cout <<"Jarineiro entrou na celula " << argumento << "\n";
    jardim->printJardim();
}
