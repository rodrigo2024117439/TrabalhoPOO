#ifndef COMANDOLARGA_H
#define COMANDOLARGA_H
#include "../Comando.h"

class ComandoLarga : public Comandos {
public:
    void executa(Jardim* jardim, const std::vector<std::string>& args) override;
};
#endif