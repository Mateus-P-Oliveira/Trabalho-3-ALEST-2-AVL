#include <iostream>
using namespace std;

#include "ABP.h"

int main() {
  
  ABP B;
    
 
  for(int i = 10; i>=5;i--){
    B.insere(i);
  }
  B.insere(20);
  
  B.CaminhaCENTRAL();
  B.GeraDOT();
  B.BalanceiaArvore();
  B.GeraDOT();
  B.CaminhaCENTRAL();

  //Arvores em que a forma de balanceamento nao funciona direito devido a ficarem com mesmos valores no emcaminhamento da arvore
  //---------------------------
  /*B.insere(10);
  B.insere(6);
  B.insere(12);
  B.insere(11);
  for(int i=15;i<25;i++)
       B.insere(i);

  B.GeraDOT();
  B.CaminhaCENTRAL();
  B.BalanceiaArvore();
  B.GeraDOT();
  B.CaminhaCENTRAL();*/
 //------------------------




  
  /*B.insere(100);
  B.insere(90);
  B.insere(95);

  B.insere(50);
  B.insere(40);
  B.insere(30);
  B.insere(20);
  B.CaminhaCENTRAL();
  B.GeraDOT();
  B.BalanceiaArvore();
  B.CaminhaCENTRAL();
  //--------------------------------

  /*for(int i = 127; i < 190; i++){
    B.insere(i);
  }
  B.CaminhaCENTRAL();
  B.GeraDOT();
  B.BalanceiaArvore();
  B.CaminhaCENTRAL();*/


    return 0;
}


