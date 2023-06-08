/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#include "Arduino.h"
#include "RGBlib.h"


Cor RGB::cores[] = {
  {255, 0, 0},               // vermelho
  {255, 150, 0},               // laranja
  {255, 255, 0},               // amarelo
  {0, 255, 0},               // verde
  {0, 255, 180},               // ciano
  {0, 0, 255},               // azul
  {100, 0, 255},               // roxo
  {255, 0, 255},               // rosa

  {160, 80, 0},               // marrom
  {255, 255, 255}               // branco
};

corRel RGB::coresRel[] = {
  {"Vermelho", 0},
  {"Laranja", 1},
  {"Amarelo", 2},
  {"Verde", 3},
  {"Ciano", 4},
  {"Azul", 5},
  {"Roxo", 6},
  {"Rosa", 7},
  {"Marrom", 8},
  {"Branco", 9}
}

RGB::RGB(int vermelho, int azul, int verde)
{
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  _vermelho = vermelho;
  _verde = verde;
  _azul = azul;
}
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
  } else if (cor == "Branco") {
    analogWrite(_vermelho, cores[9].vm);
    analogWrite(_verde, cores[9].vd);
    analogWrite(_azul, cores[9].az);
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

void RGB::rave(int ms)
{
  for(int i = 0; i < 1536; i += 32){
    if(i < 256){ // VERMELHO -> AMARELO
      analogWrite(_vermelho, 255);
      analogWrite(_verde, i);
      analogWrite(_azul, 0);
    }
    else if(i > 256 && i < 512){ // AMARELO -> VERDE
      analogWrite(_vermelho, 255 - (i - 255));
      analogWrite(_verde, 255);
      analogWrite(_azul, 0);
    }
    else if(i > 512 && i < 768){ // VERDE -> CIANO
      analogWrite(_vermelho, 0);
      analogWrite(_verde, 255);
      analogWrite(_azul, (i - 512));
    }
    else if(i > 768 && i < 1024){ // CIANO -> AZUL
      analogWrite(_vermelho, 0);
      analogWrite(_verde, 255 - (i-768));
      analogWrite(_azul, 255);
    }
    else if(i > 1024 && i < 1280){ // AZUL -> ROSA
      analogWrite(_vermelho, i - 1024);
      analogWrite(_verde, 0);
      analogWrite(_azul, 255);
    }
    else if(i > 1280 && i < 1536){ // AZUL -> ROSA
      analogWrite(_vermelho, 255);
      analogWrite(_verde, 0);
      analogWrite(_azul, 255 - (i - 1280));
    }
    delay(ms);
  }
}

void RGB::transicao(String cor1, String cor2, int ms)
{
  for (int i = 0; i < sizeof(coresRel); i++) {
    if (coresRel[i].nome == cor1) {
      indice1 = i;
    }
    if (coresRel[i].nome == cor2) {
      indice2 = i;
    }
  }
  for(int i=0; i<cores; i++){
    if(indice1 == cores[i]){
      _cor1 = i;
    }
  }
  for(int i=0; i<cores; i++){
    if(indice2 == cores[i]){
      _cor2 = i;
    }
  }
  for(i=0; i<100; i++){
    analogWrite(_vermelho, (cores[_cor1].vm - cores[_cor2].vm)/(ms/100));
    analogWrite(_verde, (cores[_cor1].vd - cores[_cor2].vd)/(ms/100));
    analogWrite(_azul, (cores[_cor1].az - cores[_cor2].az)/(ms/100));
  }
}