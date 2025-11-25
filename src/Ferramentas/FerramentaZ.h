#ifndef TRABALHO_PRATICO_TRITURADOR_H
#define TRABALHO_PRATICO_TRITURADOR_H

#include "Ferramenta.h"

class Triturador : public Ferramenta {
    int usosRestantes;
public:
    Triturador();
    
    bool avancaInstante(Jardineiro* jardineiro, Solo* solo) override;
};

#endif //TRABALHO_PRATICO_FERRAMENTAZ_H