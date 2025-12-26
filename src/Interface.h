//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_INTERFACE_H
#define TRABALHO_PRATICO_INTERFACE_H

#include "Jardim.h"
#include <map>
#include <string>
#include "Comandos/Comando.h"

class Interface {
    Jardim* meuJardim;
    std::map<std::string, Comandos*> listaComandos;
    std::map<std::string, Jardim*> copias;

    bool processarComando(const std::string& linha);

public:
    Interface();
    ~Interface();
    void iniciar();
};


#endif //TRABALHO_PRATICO_INTERFACE_H