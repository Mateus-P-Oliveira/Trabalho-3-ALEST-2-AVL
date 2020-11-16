#ifndef _NodoABP
#define _NodoABP

class NodoABP{
  public:
    int info;
    NodoABP *pai;
    NodoABP *esq;
    NodoABP *dir;

    NodoABP(int dado);
    void imprime();
};
#endif