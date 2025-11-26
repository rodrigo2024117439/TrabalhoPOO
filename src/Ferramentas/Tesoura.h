//
// Created by Rodrigo on 31/10/2025.
//

#ifndef TRABALHO_PRATICO_TESOURA_H
#define TRABALHO_PRATICO_TESOURA_H

#include "Ferramenta.h"

class Tesoura : public Ferramenta {

public:
    Tesoura();

    bool avancaInstante(Jardineiro* jardineiro, Solo* solo) override;

    Ferramenta* duplicar() const override { return new Tesoura(*this); }
};


#endif //TRABALHO_PRATICO_TESOURA_H