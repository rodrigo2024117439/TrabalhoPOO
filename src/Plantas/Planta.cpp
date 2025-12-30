//
// Created by Rodrigo on 23/10/2025.
//

#include "Planta.h"
Planta::Planta(char s, std::string esp, int h, int a, int n, Beleza b)
    :simbolo(s), especie(esp), saude(h), agua(a),nutrientes(n), beleza(b), processada(false) {
}