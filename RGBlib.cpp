/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#include "Arduino.h"
#include "RGBlib.h"

Cor RGB::cores[] = {
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

RGB::Cor RGB::dadosVermelho = RGB::cores[0];
RGB::Cor RGB::dadosLaranja = RGB::cores[1];
RGB::Cor RGB::dadosAmarelo = RGB::cores[2];
RGB::Cor RGB::dadosVerde = RGB::cores[3];
RGB::Cor RGB::dadosCiano = RGB::cores[4];
RGB::Cor RGB::dadosAzul = RGB::cores[5];
RGB::Cor RGB::dadosRoxo = RGB::cores[6];
RGB::Cor RGB::dadosRosa = RGB::cores[7];
RGB::Cor RGB::dadosMarrom = RGB::cores[8];

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
  void RGB::acender(String cor) {
  if (cor == "Vermelho") {
    analogWrite(_vermelho, cores[0].vm);
    analogWrite(_verde, cores[0].vd);
    analogWrite(_azul, cores[0].az);
  } else if (cor == "Laranja") {
    analogWrite(_vermelho, cores[1].vm);
    analogWrite(_verde, cores[1].vd);
    analogWrite(_azul, cores[1].az);
  } else if (cor == "Amarelo") {
    analogWrite(_vermelho, cores[2].vm);
    analogWrite(_verde, cores[2].vd);
    analogWrite(_azul, cores[2].az);
  } else if (cor == "Verde") {
    analogWrite(_vermelho, cores[3].vm);
    analogWrite(_verde, cores[3].vd);
    analogWrite(_azul, cores[3].az);
  } else if (cor == "Ciano") {
    analogWrite(_vermelho, cores[4].vm);
    analogWrite(_verde, cores[4].vd);
    analogWrite(_azul, cores[4].az);
  } else if (cor == "Azul") {
    analogWrite(_vermelho, cores[5].vm);
    analogWrite(_verde, cores[5].vd);
    analogWrite(_azul, cores[5].az);
  } else if (cor == "Roxo") {
    analogWrite(_vermelho, cores[6].vm);
    analogWrite(_verde, cores[6].vd);
    analogWrite(_azul, cores[6].az);
  } else if (cor == "Rosa") {
    analogWrite(_vermelho, cores[7].vm);
    analogWrite(_verde, cores[7].vd);
    analogWrite(_azul, cores[7].az);
  } else if (cor == "Marrom") {
    analogWrite(_vermelho, cores[8].vm);
    analogWrite(_verde, cores[8].vd);
    analogWrite(_azul, cores[8].az);
  } else {
    analogWrite(_vermelho,255);
    analogWrite(_verde,0);
    analogWrite(_azul,0);
    delay(1000);
    analogWrite(_vermelho,255);
    analogWrite(_verde,0);
    analogWrite(_azul,0);
    delay(1000);
  }
}
