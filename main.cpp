#include <iostream>
using namespace std;

#include "ABP.h"

int main() {
  
  ABP B;
  
  for(int i=10;i>5;i--)
        B.insere(i);

  B.CaminhaPOS();
  B.CaminhaCENTRAL();
  //B.insere(20);
  //B.insere(5);
  //B.insere(8);
  B.GeraDOT();
  
  B.AplicaBalanceamento();

  //B.AplicaBalanceamento();
  //B.CaminhaCENTRAL();
  //B.GeraDOT();
  return 0;
}
