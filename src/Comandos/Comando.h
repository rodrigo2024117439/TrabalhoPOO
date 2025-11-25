//
// Created by Rodrigo on 14/11/2025.
//

#ifndef TRABALHO_PRATICO_COMANDO_H
#define TRABALHO_PRATICO_COMANDO_H


#include "../Jardim.h"
#include <iostream>
#include <vector>
#include <string>


class Comandos {

    public:

    virtual ~Comandos()= default;


    virtual void executa(Jardim* jardim, const std::vector<std::string>& args) = 0;
    //vurtual puro que obroga as classes filhas a implementa-lo
};


#endif //TRABALHO_PRATICO_COMANDO_H