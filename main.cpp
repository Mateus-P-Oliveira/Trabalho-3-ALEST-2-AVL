#include <iostream>
using namespace std;

#include "ABP.h"

int main() {
  
  ABP B;

  
  B.insere(100);
  B.insere(90);
  B.insere(95);

  B.insere(50);
  B.insere(40);
  B.insere(30);
  B.insere(20);
  B.GeraDOT();
  //B.CaminhaPOS();
  //B.CaminhaCENTRAL();
  //B.CalculaProfundidadeDaArvore();

  //NodoABP *nodoDesbalanceado;
  //B.CriaFilho();
  //nodoDesbalanceado = B.busca(40);
  //B.RotacionaEE(nodoDesbalanceado, nodoDesbalanceado->esq);
  B.MovendoPelaArvore();
  B.GeraDOT();
  
  //B.AplicaBalanceamento();
  //B.CaminhaCENTRAL();
  //B.GeraDOT();
  return 0;
}


