/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#include "Arduino.h"
#include "RGBlib.h"

Cor RGB::cores[] = { // cria uma array com as informações de cada cor disponível
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

corRel RGB::coresRel[] = { // cria um array com o nome das cores disponíveis e um índice
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
};
RGB::RGB(int vermelho, int verde, int azul)  // define os pinos do led
{
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  _vermelho = vermelho;
  _verde = verde;
  _azul = azul;
};

void RGB::acender(String cor) {  // escreve a cor do led conforme informações da array cores[]
  for(int i=0; i<10; i++){
    if(cor == coresRel[i].nome){
      analogWrite(_vermelho, cores[i].vm);
      analogWrite(_verde, cores[i].vd);
      analogWrite(_azul, cores[i].az);
    } else {
      analogWrite(_vermelho, 255);
      analogWrite(_verde, 0);
      analogWrite(_azul, 0);
      delay(1000);
      analogWrite(_vermelho, 255);
      analogWrite(_verde, 0);
      analogWrite(_azul, 0);
      delay(1000);
  }
  }
};

void RGB::rave(int ms)  // faz transição entre todas as cores do arco-íris
{
  for(int i = 0; i < 1536; i += 32){
    if(i >= 1280){ // AZUL -> ROSA
      analogWrite(_vermelho, 255);
      analogWrite(_verde, 0);
      analogWrite(_azul, 255 - (i - 1280));
    }
    else if(i >= 1024){ // AZUL -> ROSA
      analogWrite(_vermelho, i - 1024);
      analogWrite(_verde, 0);
      analogWrite(_azul, 255);
    }
    else if(i >= 768){ // CIANO -> AZUL
      analogWrite(_vermelho, 0);
      analogWrite(_verde, 255 - (i-768));
      analogWrite(_azul, 255);
    }
    else if(i >= 512){ // VERDE -> CIANO
      analogWrite(_vermelho, 0);
      analogWrite(_verde, 255);
      analogWrite(_azul, (i - 512));
    }
    else if(i >= 256){ // AMARELO -> VERDE
      analogWrite(_vermelho, 255 - (i - 255));
      analogWrite(_verde, 255);
      analogWrite(_azul, 0);
    }
    else if(i < 256){ // VERMELHO -> AMARELO
      analogWrite(_vermelho, 255);
      analogWrite(_verde, i);
      analogWrite(_azul, 0);
    }
    delay(ms);
  }
};

void RGB::transicao(String cor1, String cor2, int ms)  // faz transição entre duas cores específicas
{
  for (int i = 0; i < sizeof(coresRel); i++) {
    if (coresRel[i].nome == cor1) {
      indice1 = coresRel[i].indice;
    }
    if (coresRel[i].nome == cor2) {
      indice2 = coresRel[i].indice;
    }
  }
  for(int i=0; i < sizeof(cores); i++){
    if(indice1 == i){
      _cor1 = coresRel[i].indice;
    }
  }
  for(int i=0; i<cores; i++){
    if(indice2 == i){
      _cor2 = coresRel[i].indice;
    }
  }
  double vmDiff = cores[indice1].vm - cores[indice2].vm;
  double vdDiff = cores[indice1].vd - cores[indice2].vd;
  double azDiff = cores[indice1].az - cores[indice2].az;
  for(int i=0; i<100; i++){
    analogWrite(_vermelho, vmDiff/(ms/100));
    analogWrite(_verde, vdDiff/(ms/100));
    analogWrite(_azul, azDiff/(ms/100));
    delay(ms);
  }
  for(int i=0; i<100; i++){
    analogWrite(_vermelho, -vmDiff/(ms/100));
    analogWrite(_verde, -vdDiff/(ms/100));
    analogWrite(_azul, -azDiff/(ms/100));
    delay(ms);
  }
}

