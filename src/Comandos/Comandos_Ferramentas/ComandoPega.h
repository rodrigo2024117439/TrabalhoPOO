#ifndef COMANDOPEGA_H
#define COMANDOPEGA_H
#include "../Comando.h"

class ComandoPega : public Comandos {
public:
    void executa(Jardim* jardim, const std::vector<std::string>& args) override;
};
#endif