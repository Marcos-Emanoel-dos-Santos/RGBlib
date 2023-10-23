/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#ifndef RGBlib_h
#define RGBlib_h

#include "Arduino.h"

struct Cor {
  byte vm; // Valor de Vermelho
  byte vd; // Valor de Verde
  byte az; // Valor de Azul
};
struct corRel {
  String nome;
  int indice;
};

class RGB
{
  public:
    RGB(int vermelho, int verde, int azul);
    void acender(String cor = "Vermelho");
    void rave(int ms = 0);
    void transicao(String cor1 = "Azul", String cor2 = "Rosa", int ms = 100);
  private:
    int _vermelho; int _verde; int _azul;
    int indice1 = -1; int indice2 = -1;
    int _cor1 = -1; int _cor2 = -1;
    int vmDiff = 0; int vdDiff = 0; int azDiff = 0;
    static Cor cores[];
    static corRel coresRel[];
};

#endif
