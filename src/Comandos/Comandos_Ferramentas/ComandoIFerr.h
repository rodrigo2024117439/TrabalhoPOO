#ifndef COMANDOIFERR_H
#define COMANDOIFERR_H
#include "../Comando.h"

class ComandoIFerr : public Comandos {
public:
    void executa(Jardim* jardim, const std::vector<std::string>& args) override;
};
#endif