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
    RGB(uint8_t vermelho, uint8_t verde, uint8_t azul); // 3 pinos para o funcionamento do RGB
    void acender(String cor = "Vermelho");
    void rave(int ms = 0);
    void transicao(String cor1 = "Azul", String cor2 = "Rosa", int ms = 100);

  private:
    static CorComNome Cores[];
    uint8_t _vermelho; uint8_t _verde; uint8_t _azul; // tratamento dos pinos dentro do cpp
    int indice1 = 0; int indice2 = 0;
    int _cor1 = 0; int _cor2 = 0; // descontinuado
    uint8_t vmDiff = 0; uint8_t vdDiff = 0; uint8_t azDiff = 0; // diferenças entre as cores (transicao)
};

#endif
