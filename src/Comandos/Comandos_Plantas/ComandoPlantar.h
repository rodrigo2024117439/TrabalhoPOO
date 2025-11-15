//
// Created by Rodrigo on 15/11/2025.
//

#ifndef TRABALHO_PRATICO_COMANDOPLANTAR_H
#define TRABALHO_PRATICO_COMANDOPLANTAR_H

#include "../Comando.h"

class ComandoPlantar: public Comandos {
public:
    void executa(Jardim* jardim, const std::vector<std::string>& args) override;
};


#endif //TRABALHO_PRATICO_COMANDOPLANTAR_H