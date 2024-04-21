/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#ifndef RGBlib_h
#define RGBlib_h

#include <Arduino.h>

struct CorComNome {
  String nome;
  byte vm;
  byte vd;
  byte az;
}

class RGB
{
  public:
    RGB(unit8_t vermelho, unit8_t verde, unit8_t azul); // 3 pinos para o funcionamento do RGB
    void acender(String cor = "Vermelho");
    void rave(int ms = 0);
    void transicao(String cor1 = "Azul", String cor2 = "Rosa", int ms = 100);

  private:
    static CorComNome Cores[];
    unit8_t _vermelho; unit8_t _verde; unit8_t _azul; // tratamento dos pinos dentro do cpp
    int indice1 = 0; int indice2 = 0;
    int _cor1 = 0; int _cor2 = 0; // descontinuado
    unit8_t vmDiff = 0; unit8_t vdDiff = 0; unit8_t azDiff = 0; // diferenças entre as cores (transicao)
};

#endif
