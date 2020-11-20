#include <iostream>
using namespace std;

#include "ABP.h"

int main() {
  
  ABP B;
  
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
  //B.GeraDOT();
  return 0;
}
