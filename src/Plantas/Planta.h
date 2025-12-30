    //
// Created by Rodrigo on 23/10/2025.
//

#ifndef TRABALHO_PRATICO_PLANTA_H
#define TRABALHO_PRATICO_PLANTA_H
#include <string>

class Solo;
class Jardim;
enum class Beleza { FEIA, BONITA, NEUTRA };

class Planta {
protected:
    int saude;
    int agua;
    int nutrientes;
    char simbolo;
    std::string especie;
    bool processada;
    Beleza beleza;

    public:
    Planta(char s, std::string esp, int h, int a, int n, Beleza b);

    virtual ~Planta() = default;
    virtual void avancaInstante(Solo* solo, Jardim* jardim, int l, int c) = 0;
    virtual Planta* duplicar() const = 0;
    bool foiProcessadaEsteTurno() const { return processada; }
    void setProcessadaEsteTurno(bool estado) { processada = estado; }

    char getSimbolo() const  {return simbolo; }
    std::string getEspecie() const { return especie; }
    int getSaude() const { return saude; }
    int getAgua() const { return agua; }
    int getNutrientes() const { return nutrientes; }
    Beleza getBeleza() const { return beleza; }
};
#endif //TRABALHO_PRATICO_PLANTA_H