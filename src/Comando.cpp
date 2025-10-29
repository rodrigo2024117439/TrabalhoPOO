//
// Created by Rodrigo on 23/10/2025.
//

#include "Comando.h"
#include <iostream>
#include <sstream>

#include "Jardim.h"

Comando::Comando(const std::string &linha) : texto(linha) {
    std::istringstream iss(linha);
    std::string p;
    while (iss >> p)
        partes.push_back(p);
}

void Comando::validar() {
    if (partes.empty()) return;

    std::string cmd = partes[0];

    if (cmd == "jardim" && partes.size() == 3)
        try {
            int linha = stoi(partes[1]);
            int coluna = stoi(partes[2]);

            if (linha < 1 || linha > 26 || coluna < 1 || coluna > 26) {
                std::cout<< "ERRO! O jardim deve ser no maximo 26*26\n";
            }else {


            }
        }catch (...) {
            std::cout<<"ERRO! Use apenas números inteiros\n";
        }

    else if (cmd == "planta" && partes.size() == 3)
        std::cout << "Plantar tipo " << partes[2] << " em " << partes[1] << "\n";

    else if (cmd == "colhe" && partes.size() == 2)
        std::cout << "Colher planta em " << partes[1] << "\n";

    else if (cmd == "avanca" && (partes.size() == 1 || partes.size() == 2))
        std::cout << "A avançar " << (partes.size() == 2 ? partes[1] : "1") << " instantes\n";

    else if (cmd == "entra" && partes.size() == 2)
        std::cout << "Jardineiro entra em " << partes[1] << "\n";

    else if (cmd == "sai" && partes.size() == 1)
        std::cout << "Jardineiro sai do jardim\n";

    else if (cmd == "compra" && partes.size() == 2)
        std::cout << "Comprar ferramenta tipo " << partes[1] << "\n";

    else if (cmd == "fim")
        std::cout << "Terminar programa\n";

    else
        std::cout << "[ERRO] Comando invalido ou parametros errados!\n";
}
