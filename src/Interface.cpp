#include "Interface.h"
#include <iostream>
#include <string>
#include "Jardim.h"
#include <fstream>
#include "Parser.h"
#include "Comandos/Comandos_Jardineiro/ComandoEntra.h"
#include "Comandos/Comandos_Jardineiro/ComandoSai.h"
#include "Comandos/Comandos_Jardineiro/ComandoColhe.h"
#include "Comandos/Comandos_Plantas/ComandoLPlantas.h"
#include "Comandos/Comandos_mover/ComandoCima.h"
#include "Comandos/Comandos_mover/ComandoBaixo.h"
#include "Comandos/Comandos_mover/ComandoEsq.h"
#include "Comandos/Comandos_mover/ComandoDir.h"
#include "Comandos/Comandos_Plantas/ComandoPlantar.h"
#include "Comandos/Comandos_Plantas/ComandoLPlantaEsp.h"
#include "Comandos/ComandoLArea.h"
#include "Comandos/ComandoAvanca.h"
#include "Comandos/Comandos_Ferramentas/ComandoIFerr.h"
#include "Comandos/Comandos_Ferramentas/ComandoPega.h"
#include "Comandos/Comandos_Ferramentas/ComandoLarga.h"
#include "Comandos/ComandoCompra.h"
#include "Comandos/ComandoLSolo.h"

Interface::Interface() : meuJardim(nullptr) {
    listaComandos["entra"] = new ComandoEntra();
    listaComandos["sai"] = new ComandoSai();
    listaComandos["colhe"] = new ComandoColhe();
    listaComandos["lplantas"] = new ComandoLPlantas();
    listaComandos["c"] = new ComandoCima();
    listaComandos["b"] = new ComandoBaixo();
    listaComandos["e"] = new ComandoEsq();
    listaComandos["d"] = new ComandoDir();
    listaComandos["planta"] = new ComandoPlantar();
    listaComandos["lplanta"] = new ComandoLPlantaEsp();
    listaComandos["larea"] = new ComandoLArea();
    listaComandos["avanca"] = new ComandoAvanca();
    listaComandos["iferr"] = new ComandoIFerr();
    listaComandos["pega"] = new ComandoPega();
    listaComandos["larga"] = new ComandoLarga();
    listaComandos["compra"] = new ComandoCompra();
    listaComandos["lsolo"] = new ComandoLSolo();
}

Interface::~Interface() {
    delete meuJardim;
    for (auto const &[nome, comando]: listaComandos) {
        delete comando;
    }
    for (auto const& [nome, jardim] : copias) {
        delete jardim;
    }
    copias.clear();
}

bool Interface::processarComando(const std::string &linha) {
    if (linha.empty()) {
        return true;
    }

    Parser parser(linha);
    std::string nomeCmd = parser.getNome();
    
    if (nomeCmd == "fim") {
        return false;
    }

    if (nomeCmd == "jardim") {
        if (meuJardim != nullptr) {
            std::cout << "ERRO- O jardim ja foi criado! Nao pode ser recriado.\n";
        } else if (parser.getNumArgs() != 2) {
            std::cout << "ERRO - Uso: jardim <linhas> <colunas>\n";
        } else {
            try {
                std::vector<std::string> args = parser.getArgs();
                int lin = std::stoi(args[0]);
                int col = std::stoi(args[1]);

                if (lin < 1 || lin > 26 || col < 1 || col > 26) {
                    std::cout << "ERRO- O jardim deve ter no maximo 26x26 e no minimo 1x1.\n";
                } else {
                    meuJardim = new Jardim(lin, col);
                    std::cout << "Jardim de " << lin << "x" << col << " criado.\n";
                    meuJardim->printJardim();
                }
            } catch (...) {
                std::cout << "ERRO- Linhas e colunas devem ser numeros inteiros.\n";
            }
        }
        return true;
    }

    if (nomeCmd == "executa") {
        if (parser.getNumArgs() != 1) {
            std::cout << "Erro: Uso -> executa <nome_ficheiro>\n";
        } else {
            std::string nomeFich = parser.getArgs()[0];
            std::ifstream ficheiro(nomeFich);
            if (!ficheiro.is_open()) {
                std::cout << "Erro: Nao foi possivel abrir o ficheiro " << nomeFich << "\n";
            } else {
                std::string linhaFicheiro;
                while (std::getline(ficheiro, linhaFicheiro)) {
                    if (!processarComando(linhaFicheiro)) {
                        ficheiro.close();
                        return false;
                    }
                }
                ficheiro.close();
            }
        }
        return true;
    }

    if (meuJardim == nullptr) {
        std::cout << "ERRO- Crie um jardim primeiro com o comando 'jardim <lin> <col>'.\n";
        return true;
    }

    if (nomeCmd == "grava") {
        if (parser.getNumArgs() != 1) {
            std::cout << "Erro: Uso -> grava <nome>\n";
        } else {
            std::string nome = parser.getArgs()[0];
            if (copias.count(nome)) delete copias[nome];
            copias[nome] = new Jardim(*meuJardim);
            std::cout << "Jardim gravado com o nome '" << nome << "'.\n";
        }
        return true;
    }

    if (nomeCmd == "recupera") {
        if (parser.getNumArgs() != 1) {
            std::cout << "Erro: Uso -> recupera <nome>\n";
        } else {
            std::string nome = parser.getArgs()[0];
            if (copias.find(nome) == copias.end()) {
                std::cout << "Erro: Nao existe gravacao com esse nome.\n";
            } else {
                delete meuJardim;
                meuJardim = new Jardim(*copias[nome]);
                std::cout << "Jardim recuperado para o estado de '" << nome << "'.\n";
                meuJardim->printJardim();
            }
        }
        return true;
    }

    if (nomeCmd == "apaga") {
        if (parser.getNumArgs() != 1) {
            std::cout << "ERRO: Uso -> apaga <nome>\n";
        } else {
            std::string nome = parser.getArgs()[0];
            auto iter = copias.find(nome);
            if (iter == copias.end()) {
                std::cout << "ERRO: esse save nao existe\n";
            } else {
                delete iter->second;
                copias.erase(iter);
                std::cout << "Gravacao " << nome << " apagada\n";
            }
        }
        return true;
    }

    if (listaComandos.count(nomeCmd)) {
        listaComandos[nomeCmd]->executa(meuJardim, parser.getArgs());
    } else {
        std::cout << "[ERRO] Comando '" << nomeCmd << "' invalido ou desconhecido.\n";
    }

    return true;
}

void Interface::iniciar() {
    std::string linha;
    std::cout << "----> Simulador de Jardim <----\n";
    std::cout << "Primeiro comando a ser utilizado: 'jardim <linhas> <colunas>'\n";
    std::cout << "Escreva 'fim' para sair.\n";
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, linha) || !processarComando(linha)) {
            std::cout << "Programa terminado.\n";
            break;
        }
    }
}