#include "ComandoCompra.h"
#include "../Jardim.h"
#include "../Jardineiro.h"
#include "../../Ferramentas/Regador.h"
#include "../../Ferramentas/Adubo.h"
#include "../../Ferramentas/Tesoura.h"
#include "../../Ferramentas/FerramentaZ.h"
#include <iostream>

void ComandoCompra::executa(Jardim* jardim, const std::vector<std::string>& args) {
    if (args.size() != 1) {
        std::cout << "Uso: compra <tipo> (g=regador, a=adubo, t=tesoura, z=triturador)\n";
        return;
    }

    char tipo = args[0][0];
    Ferramenta* nova = nullptr;

    switch (tipo) {
        case 'g': nova = new Regador(); break;
        case 'a': nova = new Adubo(); break;
        case 't': nova = new Tesoura(); break;
        case 'z': nova = new FerramentaZ(); break;
        default:
            std::cout << "Erro: Tipo de ferramenta desconhecido.\n";
            return;
    }

    if (nova != nullptr) {
        if (jardim->getJardineiro()->adicionarFerramenta(nova)) {
            std::cout << "Compra efetuada com sucesso, " << nova->getTipo() << " adicionado a mochila.\n";
        } else {
            std::cout << "Erro: A mochila esta cheia.\n";
            delete nova;
        }
    }
}