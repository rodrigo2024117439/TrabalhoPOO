//
// Created by diogo on 30/10/2025.
//
#ifndef TRABALHO_PRATICO_REGADOR_H
#define TRABALHO_PRATICO_REGADOR_H

#include "Ferramenta.h"
#include "../Settings.h"

class Regador : public Ferramenta {
    int aguaRestante;
public:
    Regador();

    int getAguaRestante() const { return aguaRestante; }

    void avancaInstante(Jardineiro* jardineiro) override;
};

#endif
