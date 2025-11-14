//
// Created by Rodrigo on 14/11/2025.
//

#ifndef TRABALHO_PRATICO_COMANDOCIMA_H
#define TRABALHO_PRATICO_COMANDOCIMA_H
#include "Comando.h"


class ComandoCima:public Comandos {
public:
    void executa(Jardim* jardim, const std::vector<std::string>& args) override;
};


#endif //TRABALHO_PRATICO_COMANDOCIMA_H