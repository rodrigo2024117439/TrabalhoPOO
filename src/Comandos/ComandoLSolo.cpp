//
// Created by Rodrigo on 27/11/2025.
//

#include "ComandoLSolo.h"

#include "../Plantas/Planta.h"
#include "../Jardim.h"
#include "../Solo.h"
#include "../Ferramentas/Ferramenta.h"

void ComandoLSolo::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.size() < 1) {
        std::cout << "ERRO: Uso -> lsolo <posicao> [raio]\n";
        return;
    }

    std::string pos = args[0];
    int l = tolower(pos[0]) - 'a';
    int c = tolower(pos[1]) - 'a';
    int raio = 0;

    if (args.size() >= 2) {
        try { raio = std::stoi(args[1]); } catch (...) { raio = 0; }
    }

    for (int i = l - raio; i <= l + raio; ++i) {
        for (int j = c - raio; j <= c + raio; ++j) {
            Solo* s = jardim->getSolo(i, j); // O getSolo já valida limites
            if (s != nullptr) {
                std::cout << "--- Posicao [" << static_cast<char>('A'+i) << static_cast<char>('A'+j) << "] ---\n";
                std::cout << "Solo: Agua=" << s->getAgua() << ", Nutrientes=" << s->getNutrientes() << "\n";
                
                if (s->getPlanta()) {
                    std::cout << "  Planta: " << s->getPlanta()->getEspecie() 
                              << " (Saude: " << s->getPlanta()->getSaude() << ")\n";
                }
                if (s->getFerramenta()) {
                    std::cout << "  Ferramenta no chao: " << s->getFerramenta()->getTipo() 
                              << " (S/N: " << s->getFerramenta()->getNumSerie() << ")\n";
                }
            }
        }
    }
}