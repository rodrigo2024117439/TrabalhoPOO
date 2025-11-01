//
// Created by Rodrigo on 31/10/2025.
//

#ifndef TRABALHO_PRATICO_PLANTAEXOTICA_H
#define TRABALHO_PRATICO_PLANTAEXOTICA_H
#include "planta.h"


class PlantaExotica: public Planta {
    public:PlantaExotica();

    void avancaInstante(Solo *solo) override;
};


#endif //TRABALHO_PRATICO_PLANTAEXOTICA_H