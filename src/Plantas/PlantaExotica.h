#ifndef TRABALHO_PRATICO_PLANTAEXOTICA_H
#define TRABALHO_PRATICO_PLANTAEXOTICA_H
#include "Planta.h"

class PlantaExotica: public Planta {
public:
    PlantaExotica();

    void avancaInstante(Solo *solo, Jardim* jardim, int l, int c) override;
};

#endif