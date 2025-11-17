//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_SOLO_H
#define TRABALHO_PRATICO_SOLO_H

class Planta;
class Ferramenta;

class Solo {
    int agua;
    int nutrientes;
    Planta* planta;
    Ferramenta* ferramenta;

public:
    Solo();
    ~Solo();

    int getAgua() const { return agua; }
    int getNutrientes() const { return nutrientes; }
    Planta* getPlanta() const { return planta; }
    Ferramenta* getFerramenta() const { return ferramenta; }

    char getSimbolo() const;

    void setPlanta(Planta* p);
    void setFerramenta(Ferramenta* f);
    void setAgua(int novoValor);
    void setNutrientes(int novoValor);
};
#endif //TRABALHO_PRATICO_SOLO_H