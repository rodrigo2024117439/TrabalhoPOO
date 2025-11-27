//
// Created by Rodrigo on 27/11/2025.
//

#ifndef TRABALHO_PRATICO_COMANDOLSOLO_H
#define TRABALHO_PRATICO_COMANDOLSOLO_H
#include "Comando.h"

class ComandoLSolo: public Comandos {

public:
    void executa (Jardim *jardim, const std::vector<std::string> &args) override;
};


#endif //TRABALHO_PRATICO_COMANDOLSOLO_H