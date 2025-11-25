#ifndef TRABALHO_PRATICO_ADUBO_H
#define TRABALHO_PRATICO_ADUBO_H

#include "Ferramenta.h"

class Adubo: public Ferramenta {
    int usosRestantes;

public:
    Adubo();
    bool avancaInstante(Jardineiro* jardineiro, Solo* solo) override;
};
#endif //TRABALHO_PRATICO_ADUBO_H