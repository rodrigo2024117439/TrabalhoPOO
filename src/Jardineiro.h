//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_JARDINEIRO_H
#define TRABALHO_PRATICO_JARDINEIRO_H

#include <vector>
#include "Ferramentas/Ferramenta.h"

class Jardineiro {
    int lin, col;
    bool noJardim;
    std::vector<Ferramenta*> inventario;
    Ferramenta* ferramentaNaMao;

    int movimentosTurno;
    int entradasSaidasTurno;
    int plantacoesTurno;
    int colheitasTurno;

    public:
    Jardineiro();
    Jardineiro(const Jardineiro &outro);
    ~Jardineiro();

    void setPos(int l, int c) { lin = l; col = c; }
    int getLin() const { return lin; }
    int getCol() const { return col; }
    void setNoJardim(bool estado) { noJardim = estado; }
    bool estaNoJardim() const { return noJardim; }
    char getSimbolo() const { return '*'; }

    bool podeMover() const;
    bool podeEntrarSair() const;
    bool podePlantar() const;
    bool podeColher() const;

    void resetContadoresTurno();
    void mover();
    void entrarSair();
    void plantar();
    void colher();

    Ferramenta* getFerramentaNaMao() const { return ferramentaNaMao; }
    bool equiparFerramenta(int index);
    void desequiparFerramenta();
    bool adicionarFerramenta(Ferramenta* f);
    void removerFerramentaPartida();
    std::string getInventarioString() const;
};
#endif //TRABALHO_PRATICO_JARDINEIRO_H