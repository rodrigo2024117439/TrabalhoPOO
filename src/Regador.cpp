//
// Created by diogo on 30/10/2025.
//
#include "Regador.h"
#include "Jardineiro.h"
#include "Solo.h"

Regador::Regador() : Ferramenta('g', "Regador"),
                     aguaRestante(Settings::Regador::capacidade) {
}

// Meta 2
void Regador::avancaInstante(Jardineiro* jardineiro) {
}