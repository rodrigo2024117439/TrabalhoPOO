//
// Created by Rodrigo on 27/11/2025.
//

#include "ComandoLSolo.h"

#include "../Plantas/Planta.h"
#include "../Jardim.h"
#include "../Solo.h"
#include "../Ferramentas/Ferramenta.h"

void ComandoLSolo::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.empty() || args.size() > 2) {
        std::cout << "Erro: Este comando aceita no maximo 2 argumentos (posicao e raio)";
        return;
    }

    std::string pos = args[0];

    if (pos.length() != 2 || !isalpha(pos[0]) || !isalpha(pos[1])) {
        std::cout << "Erro: Posicao invalida. Use duas letras (ex: ab).\n";
        return;
    }

    int centroLin = tolower(pos[0]) - 'a';
    int centroCol = tolower(pos[1]) - 'a';
    int raio = 0;


    if (args.size() == 2) {
        try {
            raio = std::stoi(args[1]);
            if (raio < 0)
                throw std::invalid_argument("negativo");
        } catch (...) {
            std::cout << "Erro: O raio deve ser um numero inteiro positivo.\n";
            return;
        }
    }

    bool encontrado = false;
    std::cout << "--->Detalhes do solo:\n";
    for (int i = centroLin - raio; i <= centroLin + raio; i++) {
        for (int j = centroCol - raio; j <= centroCol + raio; j++) {
            if (i >= 0 && i < jardim->getLinhas() && j >= 0 && j < jardim->getColunas()) {
                Solo *solo = jardim->getSolo(i, j);
                encontrado = true;

                char linhaChar = 'a' + i;
                char colunaChar = 'a' + j;

                std::cout << "[" << linhaChar << colunaChar << "] ";
                std::cout << "Agua: " << solo->getAgua() << ", Nutr: " << solo->getNutrientes();

                if (solo->getPlanta()) {
                    std::cout << " | Planta: " << solo->getPlanta()->getEspecie();
                    std::cout << " (Saude: " << solo->getPlanta()->getSaude() << ")";
                }
                if (solo->getFerramenta()) {
                    std::cout << " | Ferr: " << solo->getFerramenta()->getTipo();
                }
                std::cout << "\n";
            }
        }
    }

    if (!encontrado) {
        std::cout << "local fora do jardim";
    }
}
