/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#ifndef RGBlib_h
#define RGBlib_h

#include "Arduino.h"

class RGB
{
  public:
    RGB(int vermelho, int azul, int verde);
    void acender(String cor);
  private:
    int _vermelho; int _verde; int _azul;
};

#endif
  
