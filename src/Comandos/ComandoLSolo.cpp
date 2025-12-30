#include "ComandoLSolo.h"
#include "../Plantas/Planta.h"
#include "../Jardim.h"
#include "../Solo.h"
#include "../Ferramentas/Ferramenta.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

void ComandoLSolo::executa(Jardim *jardim, const std::vector<std::string> &args) {
    if (args.size() < 1) {
        std::cout << "ERRO: lsolo <posicao> [raio]\n";
        return;
    }

    std::string pos = args[0];
    if (pos.length() != 2 || !isalpha(pos[0]) || !isalpha(pos[1])) {
        std::cout << "ERRO: Posicao invalida.\n";
        return;
    }

    int l = tolower(pos[0]) - 'a';
    int c = tolower(pos[1]) - 'a';
    int raio = 0;

    if (args.size() >= 2) {
        try {
            raio = std::stoi(args[1]);
            if (raio < 0) raio = 0;
        } catch (...) {
            std::cout << "ERRO: Raio invalido.\n";
            return;
        }
    }

    for (int i = l - raio; i <= l + raio; ++i) {
        for (int j = c - raio; j <= c + raio; ++j) {
            Solo* s = jardim->getSolo(i, j);
            if (s != nullptr) {
                std::cout << "\nPosicao [" << static_cast<char>('A' + i) << static_cast<char>('A' + j) << "]:\n";
                std::cout << "  Solo: Agua=" << s->getAgua() << ", Nutrientes=" << s->getNutrientes() << "\n";
                
                if (s->getPlanta() != nullptr) {
                    Planta* p = s->getPlanta();
                    std::cout << "  Planta: " << p->getEspecie() << " (" << p->getSimbolo() << ")\n";
                    std::cout << "    Reserva: A=" << p->getAgua() << ", N=" << p->getNutrientes() << "\n";
                    std::cout << "    Saude: " << p->getSaude() << "\n";
                }

                if (s->getFerramenta() != nullptr) {
                    Ferramenta* f = s->getFerramenta();
                    std::cout << "  Ferramenta: " << f->getTipo() << " (S/N: " << f->getNumSerie() << ")\n";
                }
            }
        }
    }
}