/*
RGBlib
Autor: Eggsbennedit
Junho de 2023
*/

#include "Arduino.h"
#include "RGBlib.h"

CorComNome RGB::Cores[] = { // cria uma lista com nomes de cores e sua representação em RGB
  {"Vermelho", 255, 0, 0},
  {"Laranja", 255, 150, 0},
  {"Amarelo", 255, 255, 0},
  {"Verde", 0, 255, 0},
  {"Ciano", 0, 255, 180},
  {"Azul", 0, 0, 255},
  {"Roxo", 100, 0, 255},
  {"Rosa", 255, 0, 255},
  {"Marrom", 160, 80, 0},
  {"Branco", 255, 255, 255}
};

RGB::RGB(uint8_t vermelho, uint8_t verde, uint8_t azul)  // define os pinos do led
{
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  _vermelho = vermelho;
  _verde = verde;
  _azul = azul;
};

void RGB::acender(String cor) {  // escreve a cor do led conforme informações da array Cores[]
  for(int i=0; i < 10; i++){
    if(cor == Cores[i][0]){
      analogWrite(_vermelho, Cores[i].vm);
      analogWrite(_verde, Cores[i].vd);
      analogWrite(_azul, Cores[i].az);
    } else { // se a cor escolhida não existir, pisca em vermelho
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
};

void RGB::rave(int ms)  // faz transição entre todas as cores do arco-íris
{
  for(int i = 0; i < 1536; i += 32){
    if(i > 1280){ // ROSA -> VERMELHO
      analogWrite(_vermelho, 255);
      analogWrite(_verde, 0);
      analogWrite(_azul, 255 - (i - 1280));
    }
    else if(i > 1024){ // AZUL -> ROSA
      analogWrite(_vermelho, i - 1024);
      analogWrite(_verde, 0);
      analogWrite(_azul, 255);
    }
    else if(i > 768){ // CIANO -> AZUL
      analogWrite(_vermelho, 0);
      analogWrite(_verde, 255 - (i-768));
      analogWrite(_azul, 255);
    }
    else if(i > 512){ // VERDE -> CIANO
      analogWrite(_vermelho, 0);
      analogWrite(_verde, 255);
      analogWrite(_azul, (i - 512));
    }
    else if(i > 256){ // AMARELO -> VERDE
      analogWrite(_vermelho, 255 - (i - 255));
      analogWrite(_verde, 255);
      analogWrite(_azul, 0);
    }
    else if(i <= 256){ // VERMELHO -> AMARELO
      analogWrite(_vermelho, 255);
      analogWrite(_verde, i);
      analogWrite(_azul, 0);
    }
    delay(ms);
  }
};

void RGB::transicao(String cor1, String cor2, int ms)  // faz transição entre duas cores específicas
{
  for (int i = 0; i < 10; i++) { // procura as cores na array Cores
    if (Cores[i].nome == cor1) {
      indice1 = i;
    }
    if (Cores[i].nome == cor2) {
      indice2 = i;
    }
  }
  // diferença entre as duas cores escolhidas
  vmDiff = Cores[indice2].vm - Cores[indice1].vm;
  vdDiff = Cores[indice2].vd - Cores[indice1].vd;
  azDiff = Cores[indice2].az - Cores[indice1].az;

  for(int i=0; i<100; i++){
    // define a cor de cada pino como a cor inicial + 1 centésimo da diferença * i
    // para que a soma tenda à cor2.
    analogWrite(_vermelho, Cores[indice1].vm + vmDiff*i/(ms/100));
    analogWrite(_verde, Cores[indice1].vd + vdDiff*i/(ms/100));
    analogWrite(_azul, Cores[indice1].az + azDiff*i/(ms/100));
    delay(ms);
  }
  for(int i=0; i<100; i++){
    // mesmo que o anterior, mas diminui para voltar à cor1.
    analogWrite(_vermelho, Cores[indice1].vm - vmDiff*i/(ms/100));
    analogWrite(_verde, Cores[indice1].vd - vdDiff*i/(ms/100));
    analogWrite(_azul, Cores[indice1].az - azDiff*i/(ms/100));
    delay(ms);
  }
}
