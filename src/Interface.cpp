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

Interface::~Interface() {
    delete meuJardim;
}

void Interface::iniciar() {
    std::string linha;
    std::cout << "----> Simulador de Jardim <----\n";
    std::cout << "Primeiro comando a ser utilizado: 'jardim <linhas> <colunas>'\n";
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
                std::cout << "ERRO- O jardim ja foi criado! Nao pode ser recriado.\n";
            } else if (cmd.getNumArgs() != 2) {
                std::cout << "ERRO - Uso: jardim <linhas> <colunas>\n";
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


        else if (nomeCmd == "planta") {
            if (cmd.getNumArgs() != 2)
                 std::cout << "ERRO- Uso: planta <pos> <tipo>\n";
            else
                std::cout << "Plantar (nao implementado) " << cmd.getArgs()[1] << " em " << cmd.getArgs()[0] << "\n";
        }
        else if (nomeCmd == "colhe") {
             if (cmd.getNumArgs() != 1)
                 std::cout << "ERRO- Uso: colhe <pos>\n";
            else
                std::cout << "Colher em " << cmd.getArgs()[0] << "\n";
        }
        else if (nomeCmd == "avanca") {
            std::string n_instantes = (cmd.getNumArgs() == 1) ? cmd.getArgs()[0] : "1";
            std::cout << "Avancar " << n_instantes << " instantes \n";

             meuJardim->printJardim();
        }


        //-------------------listagens----------------------
        else if (nomeCmd == "larea") {
            if (cmd.getNumArgs() != 0) {
                std::cout<< "ERRO - Este comando nao aceita argumentos \n";
            } else {
                std::cout<<"A listar conteudo existentes: \n";
            }
        }

        else if (nomeCmd == "lplantas") {
            if (cmd.getNumArgs() != 0) {
                std::cout<< "ERRO - Este comando nao aceita argumentos \n";
            } else {
                std::cout<<"A listar plantas existentes: \n";
            }
        }

        else if (nomeCmd == "lferr"){
            if (cmd.getNumArgs() != 0) {
                std::cout <<" ERRO- Este comando nao aceita argumentos \n";
            }else {
                std::cout<<"A listar ferramentas existentes: \n";
            }

        }

        else if (nomeCmd == "lplanta") {
            if (cmd.getNumArgs() != 1) {
                std::cout << "ERRO- Uso: lplanta <posicao> (ex: lplanta ej)\n";
            }else {
                std::cout<< "A listar detalhes da planta na posicao " << cmd.getArgs()[0] << ": \n";
            }
        }

        else if (nomeCmd == "lsolo") {
            if (cmd.getNumArgs() <1 || cmd.getNumArgs() > 2) {
                std::cout<<"ERRO - ";
            }else {
                std::cout<<"A listar detalhes do solo";
            }
        }
        //------------------------------------------------------------------------
        //-----------------Ferrametas---------------------------

        else if (nomeCmd == "larga") {
            if (cmd.getNumArgs() != 0) {
                std::cout<<"ERRO- Este comando nao aceita argumentos \n";
            }else {
                std::cout<<"Ferramenta guardada";
            }
        }
        else if (nomeCmd == "pega") {
            if (cmd.getNumArgs() != 1) {
                std::cout << "ERRO- Uso: pega <nº de serie> \n";
            }else {
                std::cout<<"Ferramenta equipada";
            }
        }

        else if (nomeCmd == "compra") {
            if (cmd.getNumArgs() != 1) {
                std::cout << "ERRO- Uso: compra <tipo> \n";
            }else {
                std::cout<<"Ferramenta comprada";
            }
        }
        //-----------------------------------------------
        //------------------------Jardineiro--------------------
        else if (nomeCmd == "e" || nomeCmd == "d" || nomeCmd == "c" || nomeCmd == "b") {
            if (cmd.getNumArgs() != 0) {
                std::cout<<"ERRO- Este comando nao aceita argumentos \n";
            }
        }

        else if (nomeCmd == "entra") {
            if (cmd.getNumArgs() != 1) {
                std::cout << "ERRO- Uso: entra <posicao>\n";
            }
            else {
                std::cout<<"Jardineiro entrou em "<< cmd.getArgs()[0] << "\n";
            }
        }
        else if (nomeCmd == "sai") {
            if (cmd.getNumArgs() != 0) {
                std::cout << "ERRO- este comando nao aceira argumento\n";
            }else {
                std::cout<<"o hardineiro saio do jardim";
            }
        }
        //----------------------------------------------------
        //--------------comandos gerais-----------------------

        else if (nomeCmd == "grava" || nomeCmd == "recupera" || nomeCmd == "apaga" ) {
            if (cmd.getNumArgs() != 1) {
                std::cout << "ERRO- unico argomento a usar é <nome> \n";
            }
            else if (nomeCmd == "grava") {
                std::cout<<"Simulacao guardada com o nome "<<cmd.getArgs()[0]<<" \n";
            }else if (nomeCmd == "recupera") {
                std::cout<<"simulacao com o nome "<<cmd.getArgs()[0] << " recuperada \n";
            }else if (nomeCmd == "apaga") {
                std::cout<<"simulacao com o nome "<<cmd.getArgs()[0] << " apagada \n";
            }
        }

        else if (nomeCmd == "executa") {
            if (cmd.getNumArgs() != 1) {
                std::cout << "ERRO- Uso: executa <nome-do-ficheiro>\n";
            }else {
                std::cout<<"A abrir ficheiro "<<cmd.getArgs()[0];
            }
        }





        // Se o comando não for nenhum dos anteriores
        else if (!nomeCmd.empty()) { // Ignora linhas em branco
            std::cout << "[ERRO] Comando '" << nomeCmd << "' invalido ou desconhecido.\n";
        }
    }
}