#ifndef TRABALHO_PRATICO_TRITURADOR_H
#define TRABALHO_PRATICO_TRITURADOR_H

#include "Ferramenta.h"

class FerramentaZ : public Ferramenta {
    int usosRestantes;
public:
    FerramentaZ();
    
    bool avancaInstante(Jardineiro* jardineiro, Solo* solo) override;

    Ferramenta* duplicar() const override { return new FerramentaZ(*this); }
};

#endif //TRABALHO_PRATICO_FERRAMENTAZ_H