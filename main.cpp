#include <iostream>
using namespace std;

#include "ABP.h"

int main() {

  
  ABP B;
  

  B.insere(100);
  B.insere(90);
  B.insere(50);
  B.insere(40);
  B.insere(30);
  B.insere(20);
  B.insere(101);
  B.GeraDOT();
 
  //NodoABP *NodoDesbalanceado;
  //NodoDesbalanceado = B.busca(100);
  //B.RotacionaDD(NodoDesbalanceado,NodoDesbalanceado->dir);
  
  //B.GeraDOT();
  
  B.MovendoPelaArvore();
  //B.CaminhaCENTRAL();
  B.GeraDOT();
  
 
 
 /*ABP B;
  
  for(int i=10;i>5;i--)
        B.insere(i);

  
  
  B.insere(20);
  B.insere(5);
  //B.insere(8);
  B.insere(11);
  B.GeraDOT();
  //B.CaminhaPOS();
  //B.CaminhaCENTRAL();
  B.AplicaBalanceamento();
  B.GeraDOT();
  
  //B.AplicaBalanceamento();
  //B.CaminhaCENTRAL();
  //B.GeraDOT();*/
  return 0;
}
