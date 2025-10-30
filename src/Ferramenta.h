//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_FERRAMENTA_H
#define TRABALHO_PRATICO_FERRAMENTA_H
#include <string>

class Jardineiro;

class Ferramenta {
private:
    static int contadorSeries;
    int numSerie;
    char simbolo;
    std::string tipo;

public:
    Ferramenta(char s, std::string t) :simbolo(s), tipo(t) {
        numSerie = ++contadorSeries;
    }

    virtual ~Ferramenta() = default;

    int getNumSerie() const { return numSerie; }
    char getSimbolo() const { return simbolo; }
    std::string getTipo() const { return tipo; }

    virtual void avancaInstante(Jardineiro* jardineiro) {}
};
#endif //TRABALHO_PRATICO_FERRAMENTA_H