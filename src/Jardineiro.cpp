//
// Created by Rodrigo on 23/10/2025.
//

#include "Jardineiro.h"
#include "Jardineiro.h"
#include "Settings.h"

Jardineiro::Jardineiro()
    : lin(-1), col(-1), noJardim(false), ferramentaNaMao(nullptr),
      movimentosTurno(0), entradasSaidasTurno(0),
      plantacoesTurno(0), colheitasTurno(0) {
}

Jardineiro::~Jardineiro() {

    delete ferramentaNaMao;

    for (Ferramenta* f : inventario) {
        delete f;
    }
}

bool Jardineiro::podeMover() const {
    return movimentosTurno < Settings::Jardineiro::max_movimentos;
}
bool Jardineiro::podeEntrarSair() const {
    return entradasSaidasTurno < Settings::Jardineiro::max_entradas_saidas;
}
bool Jardineiro::podePlantar() const {
    return plantacoesTurno < Settings::Jardineiro::max_plantacoes;
}
bool Jardineiro::podeColher() const {
    return colheitasTurno < Settings::Jardineiro::max_colheitas;
}

void Jardineiro::resetContadoresTurno() {
    movimentosTurno = 0;
    entradasSaidasTurno = 0;
    plantacoesTurno = 0;
    colheitasTurno = 0;
}

void Jardineiro::mover() { movimentosTurno++; }
void Jardineiro::entrarSair() { entradasSaidasTurno++; }
void Jardineiro::plantar() { plantacoesTurno++; }
void Jardineiro::colher() { colheitasTurno++; }