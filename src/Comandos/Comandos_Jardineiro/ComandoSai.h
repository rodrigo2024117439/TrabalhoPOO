//
// Created by Rodrigo on 14/11/2025.
//

#ifndef TRABALHO_PRATICO_COMANDOSAIR_H
#define TRABALHO_PRATICO_COMANDOSAIR_H
#include "../Comando.h"
#include <iostream>

class ComandoSai: public Comandos {

public:
    void executa(Jardim *jardim, const std::vector<std::string>& args) override;


};


#endif //TRABALHO_PRATICO_COMANDOSAIR_H