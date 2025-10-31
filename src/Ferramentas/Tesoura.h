//
// Created by Rodrigo on 31/10/2025.
//

#ifndef TRABALHO_PRATICO_TESOURA_H
#define TRABALHO_PRATICO_TESOURA_H

#include "Ferramenta.h"

class Tesoura : public Ferramenta {

public:
    Tesoura();

    void avancaInstante(Jardineiro* jardineiro);
};


#endif //TRABALHO_PRATICO_TESOURA_H