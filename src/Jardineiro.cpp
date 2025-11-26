//
// Created by Rodrigo on 23/10/2025.
//
#include "Jardineiro.h"
#include "Settings.h"
#include <sstream>

Jardineiro::Jardineiro()
    : lin(-1), col(-1), noJardim(false), ferramentaNaMao(nullptr),
      movimentosTurno(0), entradasSaidasTurno(0),
      plantacoesTurno(0), colheitasTurno(0) {
}

Jardineiro::~Jardineiro() {

    ferramentaNaMao = nullptr;

    for (Ferramenta* f : inventario) {
        delete f;
    }
    inventario.clear();
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

bool Jardineiro::adicionarFerramenta(Ferramenta* f) {
    if (f == nullptr) return false;
    inventario.push_back(f);
    return true;
}

bool Jardineiro::equiparFerramenta(int index) {
    if (index >= 0 && index < inventario.size()) {
        ferramentaNaMao = inventario[index];
        return true;
    }
    return false;
}

void Jardineiro::desequiparFerramenta() {
    ferramentaNaMao = nullptr;
}

void Jardineiro::removerFerramentaPartida() {
    if (ferramentaNaMao == nullptr) return;

    // Procura a ferramenta partida no inventário para a apagar
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (*it == ferramentaNaMao) {
            delete *it; // Apaga da memória
            inventario.erase(it); // Remove do vetor
            break;
        }
    }
    ferramentaNaMao = nullptr;
}

std::string Jardineiro::getInventarioString() const {
    std::stringstream ss;
    ss << "Inventario do Jardineiro:\n";
    if (inventario.empty()) {
        ss << "  (Vazio)\n";
    } else {
        for (size_t i = 0; i < inventario.size(); ++i) {
            ss << "  [" << i << "] " << inventario[i]->getTipo() 
               << " (Serie: " << inventario[i]->getNumSerie() << ")";
            
            if (inventario[i] == ferramentaNaMao) {
                ss << " <--- NA MAO";
            }
            ss << "\n";
        }
    }
    return ss.str();
}

Jardineiro::Jardineiro(const Jardineiro &outro) {
    this->lin = outro.lin;
    this->col = outro.col;
    this->noJardim = outro.noJardim;
    
    this->movimentosTurno = outro.movimentosTurno;
    this->entradasSaidasTurno = outro.entradasSaidasTurno;
    this->plantacoesTurno = outro.plantacoesTurno;
    this->colheitasTurno = outro.colheitasTurno;

    this->ferramentaNaMao = nullptr;

    for (Ferramenta* f : outro.inventario) {
        Ferramenta* copia = f->duplicar();
        inventario.push_back(copia);
        if (f == outro.ferramentaNaMao) {
            ferramentaNaMao = copia;
        }
    }
}