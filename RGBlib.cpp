/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#include "Arduino.h"
#include "RGBlib.h"

struct Cor {
  byte vm; // Valor de Vermelho
  byte vd; // Valor de Verde
  byte az; // Valor de Azul
};

Cor cores[] = {
  {255, 0, 0},
  {255, 150, 0},
  {255, 255, 0},
  {0, 255, 0},
  {0, 255, 180},
  {0, 0, 255},
  {100, 0, 255},
  {255, 0, 255},
  {160, 80, 0}
};
Cor Vermelho = cores[0];
Cor Laranja = cores[1];
Cor Amarelo = cores[2];
Cor Verde = cores[3];
Cor Ciano = cores[4];
Cor Azul = cores[5];
Cor Roxo = cores[6];
Cor Rosa = cores[7];
Cor Marrom = cores[8];

RGB::RGB(int vermelho, int azul, int verde)
{
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  _vermelho = vermelho;
  _verde = verde;
  _azul = azul;
}
void RGB::acender(String cor)
{
  if(cor == "Vermelho"){
  analogWrite(_vermelho, Vermelho.vm);
  analogWrite(_verde, Vermelho.vd);
  analogWrite(_azul, Vermelho.az);
  } else
  if(cor == "Laranja"){
  analogWrite(_vermelho, Laranja.vm);
  analogWrite(_verde, Laranja.vd);
  analogWrite(_azul, Laranja.az);
  } else
  if(cor == "Amarelo"){
  analogWrite(_vermelho, Amarelo.vm);
  analogWrite(_verde, Amarelo.vd);
  analogWrite(_azul, Amarelo.az);
  } else
  if(cor == "Verde"){
  analogWrite(_vermelho, Verde.vm);
  analogWrite(_verde, Verde.vd);
  analogWrite(_azul, Verde.az);
  } else
  if(cor == "Ciano"){
  analogWrite(_vermelho, Ciano.vm);
  analogWrite(_verde, Ciano.vd);
  analogWrite(_azul, Ciano.az);
  } else
  if(cor == "Azul"){
  analogWrite(_vermelho, Azul.vm);
  analogWrite(_verde, Azul.vd);
  analogWrite(_azul, Azul.az);
  } else
  if(cor == "Roxo"){
  analogWrite(_vermelho, Roxo.vm);
  analogWrite(_verde, Roxo.vd);
  analogWrite(_azul, Roxo.az);
  } else
  if(cor == "Rosa"){
  analogWrite(_vermelho, Rosa.vm);
  analogWrite(_verde, Rosa.vd);
  analogWrite(_azul, Rosa.az);
  } else
  if(cor == "Marrom"){
  analogWrite(_vermelho, Marrom.vm);
  analogWrite(_verde, Marrom.vd);
  analogWrite(_azul, Marrom.az);
  } else {
  analogWrite(_vermelho, 255);
  analogWrite(_verde, 0);
  analogWrite(_azul, 0);
  delay(1000);
  analogWrite(_vermelho, 0);
  analogWrite(_verde, 0);
  analogWrite(_azul, 0);
  delay(1000);
  }
}
