//
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_PLANTA_H
#define TRABALHO_PRATICO_PLANTA_H
#include <string>

class Solo;

class Planta {
protected:
    int saude;
    int agua;
    int nutrientes;
    char simbolo;
    std::string especie;

    public:
    Planta(char s, std::string esp, int h, int a, int n);

    virtual ~Planta() = default;
    virtual void avancaInstante(Solo* solo) = 0;

    char getSimbolo() const  {return simbolo; }
    std::string getEspecie() const { return especie; }
    int getSaude() const { return saude; }
    int getAgua() const { return agua; }
    int getNutrientes() const { return nutrientes; }
};
#endif //TRABALHO_PRATICO_PLANTA_H