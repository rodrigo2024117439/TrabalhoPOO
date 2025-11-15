//
// Created by Rodrigo on 15/11/2025.
//

#include "ComandoPlantar.h"
#include <iostream>
#include <string>
#include <cctype>

#include "../../Plantas/Cacto.h"
#include "../../Plantas/ErvaDaninha.h"
#include "../../Plantas/PlantaExotica.h"
#include "../../Plantas/Roseira.h"
#include "../../Jardim.h"
#include "../../Jardineiro.h"
#include "../../Solo.h"


void ComandoPlantar::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERRO: este comando necessita de 2 argumentos (posicao e tipo de planta) \n";
        return;
    }

    const std::string& posicao = args[0];
    const std::string& tipo = args[1];

    if (posicao.length() != 2 || !isalpha(posicao[0]) || !isalpha(posicao[1])) {
        std::cout << "ERRO: Posicao errada";
        return;
    }

    if (tipo != "c" && tipo != "r" && tipo != "e" && tipo != "x") {
        std::cout << "ERRO: Planta tem que ser do tipo r,c,e ou x";
        return;
    }


    int index_linha = tolower(posicao[0]) - 'a';
    int index_coluna = tolower(posicao[1]) - 'a';

    if (index_linha < 0 || index_linha >= jardim->getLinhas() || index_coluna < 0 || index_coluna >= jardim->
        getColunas()) {
        std::cout << "ERRO: Posicao invalida (tem que estar no tabuleiro)";
        return;
    }


    Jardineiro *jardineiro = jardim->getJardineiro();

    if (!jardineiro->podePlantar()) {
        std::cout << "ERRO: Jardineiro ja plantou 2 vezes";
        return;
    }


    Solo *solo = jardim->getSolo(index_linha, index_coluna);

    if (solo->getPlanta() != nullptr) {
        std::cout << "ERRO: Esse lugar ja tem uma planta";
        return;
    }


    Planta *newPlanta = nullptr;
    if (tipo == "c") {
        newPlanta = new Cacto();
    } else if (tipo == "r") {
        newPlanta = new Roseira();
    } else if (tipo == "e") {
        newPlanta = new ErvaDaninha();
    } else if (tipo == "x") {
        newPlanta = new PlantaExotica();
    }

    solo->setPlanta(newPlanta);
    jardineiro->plantar();

    std::cout << "Planta do tipo " << newPlanta->getEspecie() << " plantada com sucesso";

    jardim->printJardim();
}
