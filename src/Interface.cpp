#include "Interface.h"
#include <iostream>
#include <string>

#include "Parser.h"
#include "Comandos/comandoEntra.h"
#include "Comandos/ComandoSai.h"
#include "Comandos/ComandoColhe.h"
#include "Comandos/ComandoLPlantas.h"
#include "Comandos/ComandoCima.h"
#include "Comandos/ComandoBaixo.h"
#include "Comandos/ComandoEsq.h"
#include "Comandos/ComandoDir.h"
// (Adiciona aqui o #include do ComandoPlanta.h quando o criares)

Interface::Interface() : meuJardim(nullptr) {
    listaComandos["entra"] = new ComandoEntra();
    listaComandos["sai"] = new ComandoSai();
    listaComandos["colhe"] = new ComandoColhe();
    listaComandos["lplantas"] = new ComandoLPlantas();
    listaComandos["c"] = new ComandoCima();
    listaComandos["b"] = new ComandoBaixo();
    listaComandos["e"] = new ComandoEsq();
    listaComandos["d"] = new ComandoDir();
    // (Adiciona o "planta" e os outros aqui)
}

Interface::~Interface() {
    delete meuJardim;

    for (auto const& [nome, comando] : listaComandos) {
        delete comando;
    }
}

void Interface::iniciar() {
    std::string linha;
    std::cout << "----> Simulador de Jardim <----\n";
    std::cout << "Primeiro comando a ser utilizado: 'jardim <linhas> <colunas>'\n";
    std::cout << "Escreva 'fim' para sair.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, linha);



        Parser parser(linha);
        std::string nomeCmd = parser.getNome();

        if (nomeCmd == "fim") {
            std::cout << "Programa terminado.\n";
            break;
        }

        else if (nomeCmd == "jardim") {
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
                } catch (const std::invalid_argument &e) {
                    std::cout << "ERRO- Linhas e colunas devem ser numeros inteiros.\n";
                }
            }
        }

        else if (meuJardim == nullptr && !nomeCmd.empty()) {
            std::cout << "ERRO- Crie um jardim primeiro com o comando 'jardim <lin> <col>'.\n";
        }

        else if (listaComandos.count(nomeCmd)) {
            listaComandos[nomeCmd]->executa(meuJardim, parser.getArgs());
        }

        else if (!nomeCmd.empty()) {
            std::cout << "[ERRO] Comando '" << nomeCmd << "' invalido ou desconhecido.\n";
        }
    }
}