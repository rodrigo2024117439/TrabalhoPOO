//
// Created by Rodrigo on 31/10/2025.
//

#ifndef TRABALHO_PRATICO_ERVADANINHA_H
#define TRABALHO_PRATICO_ERVADANINHA_H

#include "planta.h"

class ErvaDaninha: public Planta {
  int instDeVida;
  int instParaMultiplicar;

public:
  ErvaDaninha();

  void avancaInstante(Solo* solo, Jardim* jardim, int l, int c) override;
};


#endif //TRABALHO_PRATICO_ERVADANINHA_H