//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_INTERFACE_H
#define TRABALHO_PRATICO_INTERFACE_H

#include "Jardim.h"

class Interface {
    Jardim* meuJardim;

    bool parsePos(const std::string& posStr, int& lin, int& col)const;
    static bool parseInt(const std::string& s, int& valor);

public:
    Interface();  // Construtor
    ~Interface(); // Destrutor
    void iniciar();
};


#endif //TRABALHO_PRATICO_INTERFACE_H