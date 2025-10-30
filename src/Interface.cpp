//
// Created by Rodrigo on 23/10/2025.
//

#include "Interface.h"
#include <iostream>
#include <string> // Precisamos de std::string
#include "Comando.h"
// Jardim.h já é incluído por Interface.h

// Construtor: Começa com o jardim a não existir (nullptr)
Interface::Interface() : meuJardim(nullptr) {
}

// Destrutor: Se o jardim foi criado, temos de o apagar
Interface::~Interface() {
    delete meuJardim; // O delete ignora se for nullptr
}

void Interface::iniciar() {
    std::string linha;
    std::cout << "=== Simulador de Jardim ===\n";
    std::cout << "Primeiro comando deve ser: 'jardim <linhas> <colunas>'\n";
    std::cout << "Escreva 'fim' para sair.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, linha);

        Comando cmd(linha); // Cria o comando
        std::string nomeCmd = cmd.getNome(); // Pergunta o nome

        if (nomeCmd == "fim") {
            std::cout << "Programa terminado.\n";
            break;
        }

        // --- LÓGICA DO COMANDO "JARDIM" ---
        else if (nomeCmd == "jardim") {
            if (meuJardim != nullptr) {
                std::cout << "[ERRO] O jardim ja foi criado! Nao pode ser recriado.\n";
            } else if (cmd.getNumArgs() != 2) {
                std::cout << "[ERRO] Uso: jardim <linhas> <colunas>\n";
            } else {
                try {
                    std::vector<std::string> args = cmd.getArgs();
                    int lin = std::stoi(args[0]); // Converte arg 1 para int
                    int col = std::stoi(args[1]); // Converte arg 2 para int

                    // Validação das regras do enunciado
                    if (lin < 1 || lin > 26 || col < 1 || col > 26) {
                        std::cout << "[ERRO] O jardim deve ter no maximo 26x26 e no minimo 1x1.\n";
                    } else {
                        // SUCESSO!
                        meuJardim = new Jardim(lin, col); // <--- CRIA O JARDIM
                        std::cout << "Jardim de " << lin << "x" << col << " criado.\n";
                        meuJardim->printJardim(); // <--- MOSTRA O JARDIM
                    }
                } catch (const std::invalid_argument& e) {
                    // apanha o erro se std::stoi falhar (ex: "jardim a b")
                    std::cout << "[ERRO] Linhas e colunas devem ser numeros inteiros.\n";
                }
            }
        }

        // --- RESTO DOS COMANDOS ---

        // Se o comando não for "jardim" e o jardim ainda não existir...
        else if (meuJardim == nullptr) {
            std::cout << "[ERRO] Crie um jardim primeiro com o comando 'jardim <lin> <col>'.\n";
        }

        // Se chegarmos aqui, o jardim JÁ EXISTE e podemos processar outros comandos
        else if (nomeCmd == "planta") {
            if (cmd.getNumArgs() != 2)
                 std::cout << "[ERRO] Uso: planta <pos> <tipo>\n";
            else
                std::cout << "Plantar (nao implementado) " << cmd.getArgs()[1] << " em " << cmd.getArgs()[0] << "\n";
        }
        else if (nomeCmd == "colhe") {
             if (cmd.getNumArgs() != 1)
                 std::cout << "[ERRO] Uso: colhe <pos>\n";
            else
                std::cout << "Colher (nao implementado) em " << cmd.getArgs()[0] << "\n";
        }
        else if (nomeCmd == "avanca") {
            std::string n_instantes = (cmd.getNumArgs() == 1) ? cmd.getArgs()[0] : "1";
            std::cout << "Avancar " << n_instantes << " instantes (nao implementado)\n";
            // No futuro, depois de avançar, deve mostrar o jardim atualizado:
             meuJardim->printJardim();
        }

        // ... (colocar aqui os 'else if' para os outros comandos: 'lplantas', 'sai', etc.) ...

        // Se o comando não for nenhum dos anteriores
        else if (!nomeCmd.empty()) { // Ignora linhas em branco
            std::cout << "[ERRO] Comando '" << nomeCmd << "' invalido ou desconhecido.\n";
        }
    }
}