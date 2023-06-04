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
Cor dadosVermelho = cores[0];
Cor dadosLaranja = cores[1];
Cor dadosAmarelo = cores[2];
Cor dadosVerde = cores[3];
Cor dadosCiano = cores[4];
Cor dadosAzul = cores[5];
Cor dadosRoxo = cores[6];
Cor dadosRosa = cores[7];
Cor dadosMarrom = cores[8];

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
  analogWrite(_vermelho, dadosVermelho.vm);
  analogWrite(_verde, dadosVermelho.vd);
  analogWrite(_azul, dadosVermelho.az);
  } else
  if(cor == "Laranja"){
  analogWrite(_vermelho, dadosLaranja.vm);
  analogWrite(_verde, dadosLaranja.vd);
  analogWrite(_azul, dadosLaranja.az);
  } else
  if(cor == "Amarelo"){
  analogWrite(_vermelho, dadosAmarelo.vm);
  analogWrite(_verde, dadosAmarelo.vd);
  analogWrite(_azul, dadosAmarelo.az);
  } else
  if(cor == "Verde"){
  analogWrite(_vermelho, dadosVerde.vm);
  analogWrite(_verde, dadosVerde.vd);
  analogWrite(_azul, dadosVerde.az);
  } else
  if(cor == "Ciano"){
  analogWrite(_vermelho, dadosCiano.vm);
  analogWrite(_verde, dadosCiano.vd);
  analogWrite(_azul, dadosCiano.az);
  } else
  if(cor == "Azul"){
  analogWrite(_vermelho, dadosAzul.vm);
  analogWrite(_verde, dadosAzul.vd);
  analogWrite(_azul, dadosAzul.az);
  } else
  if(cor == "Roxo"){
  analogWrite(_vermelho, dadosRoxo.vm);
  analogWrite(_verde, dadosRoxo.vd);
  analogWrite(_azul, dadosRoxo.az);
  } else
  if(cor == "Rosa"){
  analogWrite(_vermelho, dadosRosa.vm);
  analogWrite(_verde, dadosRosa.vd);
  analogWrite(_azul, dadosRosa.az);
  } else
  if(cor == "Marrom"){
  analogWrite(_vermelho, dadosMarrom.vm);
  analogWrite(_verde, dadosMarrom.vd);
  analogWrite(_azul, dadosMarrom.az);
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
