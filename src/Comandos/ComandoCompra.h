#ifndef COMANDOCOMPRA_H
#define COMANDOCOMPRA_H
#include "Comando.h"

class ComandoCompra : public Comandos {
public:
    void executa(Jardim* jardim, const std::vector<std::string>& args) override;
};
#endif