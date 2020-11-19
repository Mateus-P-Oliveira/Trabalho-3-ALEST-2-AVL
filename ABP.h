
#ifndef _ARVBIN
#define _ARVBIN
#include <iostream>
using namespace std;

#include "NodoABP.h"

class ABP 
{
  NodoABP *Raiz; 
  int max(int a, int b); // Ve quem e maior
  NodoABP *insere(NodoABP *nodo, int n);//Insere o nodo na lista
  int CalculaProfundidade(NodoABP *n);//Retorna o tamanho da arvore
  NodoABP *busca(NodoABP *nodo, int n); //Busca o nodo dado sua posicao
  void CaminhaCENTRAL(NodoABP *nodo);//Percorre a arvore utilizando o caminho central, ver slides sobre arvores binarias de pesquisa para mais informacoes
  void CaminhaPRE(NodoABP *nodo);//Percorre o nodo usando o caminho pre fixado Ver slides arvores binarias de pesquisa
  void CaminhaPOS(NodoABP *nodo);//Percorre o nodo usando o caminho pos fixado. Ver slides arvores de pesquisa binarias
  void GeraConexoesDOT(NodoABP *nodo);//Gera as conexoes do nodo que sera inserido no arquivo para imprimi-lo
  void GeraNodosDOT(NodoABP *nodo);//Gera o nodo para o codigo imprimi-lo
  void CriaFilho(NodoABP *nodo);//Cria os filhos
public:
  ABP (); //Cria a arvore sem nada 
  NodoABP* getRaiz(); // Retorna a raiz da arvore
  int CalculaQtdDeFolhas();//Nao foi declarado
  int CalculaGrauNodo(NodoABP *n);
  void insere(int n);//Chama a funcao insere do privado
  int CalculaProfundidadeDaArvore();//Mede o tamanho da arvore
  int EncontraMenor();//Retorna o ultimo nodo da arvore
  NodoABP* busca (int n);//Chama a funcao para buscar o nodo
  void Busca_ImprimeNodo(int n);//Busca e imprime o nodo
  void CaminhaCENTRAL();//Chama a funcao caminho central
  void CaminhaPRE();//Chama a funcao para percorrer o caminho pre fixado
  void GeraConexoesDOT();//Chama a funcao geraCOnexoesDOT
  void GeraNodosDOT();//Chama a funcao geranodosDOr
  void GeraDOT();//Cria o arquivo para ser lido nos digrafos chamando todas funcoes construtoras de dot
  void CaminhaPOS();//Chama a funcao Caminha Pos
  void AplicaBalanceamento();//Chama a funcao para balancear a arvore
  //int ProfundidadeEsquerda(NodoABP *n); // Calcula profundidade das sub arvores esquerdas
  //int ProfundidadeDireita(NodoABP *n); // Calcula profundidade das sub arvores direitas
  NodoABP *RotacionaEE(NodoABP *a, NodoABP *b);// Faz a Rotacao para Esquerda-Esquerda
  NodoABP *RotacionaDD(NodoABP *a, NodoABP *b);// Faz a Rotacao para Direita-Direita
  NodoABP *RotacionaED(NodoABP *a, NodoABP *b);// Faz a Rotacao para Esquerda-Direita
  NodoABP *RotacionaDE(NodoABP *a, NodoABP *b); // Faz a Rotacao para Direita-Esquerda
  void CaminhaPOSBalanceado(NodoABP *n);//Percorre o caminho pos e aplica o balanceamento
  int FatorBalanceamento(NodoABP *n);// Faz o fator balanceamento
  void CriaFilho();//Chama a funcao cria filho
  int Altura(NodoABP *n);//Calcula a altura do nodo
};
#endif 
