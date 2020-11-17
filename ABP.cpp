
#include "ABP.h"

ABP::ABP () // Cria a arvore sem nada
{
  Raiz = NULL;
}
NodoABP* ABP::getRaiz() // Retorna a raiz da Arvore
{
  return Raiz;
}

int CalculaQtdDeFolhas(); // Nao foi declarado
int ABP::CalculaGrauNodo(NodoABP *n)//Calcula o grau do nodo
{
  int grau = 0;
  if (n->esq != NULL)
    grau ++;
  if (n->dir != NULL)
    grau ++;
return grau;
}
// ***********
int ABP::max(int a, int b) //Ve quem e maior
{
  if (a>b)
    return a;
  else return b;    
}
// ************************************
void ABP::insere(int n) //Chama a funcao insere 
{
  Raiz = insere(Raiz,n);
}
// ************************************
NodoABP* ABP::insere(NodoABP *nodo, int n)//Insere o valor do nodo na arvore e decide para qual lado ele ira inserir de acordo com o tamnho de n
{
  if (nodo == NULL) { // encontrou o local para inserir
    NodoABP *aux;
    aux = new NodoABP(n);
    return aux;
  }
  else {
          if (n <= nodo->info) 
            nodo->esq =  insere(nodo->esq, n);
          else 
            nodo->dir = insere(nodo->dir, n);
    }
    return nodo;
}
// ************************************
int ABP::ABP::CalculaProfundidadeDaArvore()//Acessa a funcao para calcular a profundidade da arvore
{
  return CalculaProfundidade(Raiz); 
}
// ************************************
int ABP::CalculaProfundidade(NodoABP *n)// Calcula a profundidade da arvore
{ 
  int alturaEsq, alturaDir;
  if (n != NULL)
  {
    alturaEsq = CalculaProfundidade(n->esq);
    alturaDir = CalculaProfundidade(n->dir);
    return 1 + max (alturaEsq, alturaDir);//Max retorna o valor mais alto entre esq e direita, caso sejam iguais ele retorna esquerda
  }
  else return 0;
}
// ************************************
int ABP::ProfundidadeEsquerda(NodoABP *n){
  int alturaEsq;
  if(n != NULL){
    alturaEsq = ProfundidadeEsquerda(n->esq);
    return 1 + alturaEsq;
  }
  else return 0;
}
// ************************************
int ABP::ProfundidadeDireita(NodoABP *n){
  int alturaDir;
  if(n != NULL){
    alturaDir = ProfundidadeDireita(n->dir);
    return 1 + alturaDir;
  }
  else return 0;
}
// ************************************
int ABP::EncontraMenor() { //Encontra o nodo na ultima posicao
  NodoABP *aux = Raiz;
    // loop down to find the leftmost leaf
    while (aux->esq != NULL) 
    {
      aux = aux->esq;
    }
  return(aux->info);
}
// ************************************
NodoABP* ABP::busca (int n) //Chama a funcao que procura um nodo
{
  return busca(Raiz, n);
}
// ************************************
void ABP::Busca_ImprimeNodo(int n)//Busca e imprime o nodo quando encontra ele
{
  NodoABP* aux;
  aux = busca(n);
  if (aux == NULL)
    cout << "Nao achou" << endl;
  else
  {
    cout << "Achou aqui:" << endl;
    aux->imprime();
  }
}
// ************************************
NodoABP* ABP::busca(NodoABP *nodo, int n) //Busca o nodo dado sua posicao
{
  if (nodo == NULL || nodo->info == n)
      return nodo;
  if (nodo->info > n)
      return busca (nodo->esq, n);
  else
      return busca (nodo->dir, n);
}
// ************************************
void ABP::CaminhaCENTRAL()//Chama a funcao caminhaCentral
{
  cout << "Caminhamento Central: ";
  CaminhaCENTRAL(Raiz);
  cout << endl;
}
// ************************************
void ABP::CaminhaCENTRAL(NodoABP *nodo)//Percorre a arvore utilizando o caminho central, ver slides sobre arvores binarias de pesquisa para mais informacoes
{
  if(nodo == NULL) return;
  CaminhaCENTRAL(nodo->esq);
  cout << nodo->info << " ";
  CaminhaCENTRAL(nodo->dir);

}
// ************************************
void ABP::GeraConexoesDOT(NodoABP *nodo) //Gera as conexoes do nodo que sera inserido no arquivo para imprimi-lo
{
    if(nodo == NULL) return;
    GeraConexoesDOT(nodo->esq);
    //   "nodeA":dir -> "nodeB";
    if (nodo->esq)
        cout << "\"node" << nodo->info << "\":esq -> \"node" << nodo->esq->info << "\"" <<endl;
    GeraConexoesDOT(nodo->dir);
    if (nodo->dir)
        cout << "\"node" << nodo->info << "\":dir -> \"node" << nodo->dir->info << "\""<<endl;
}

void ABP::GeraNodosDOT(NodoABP *nodo)//Gera o nodo para o codigo imprimi-lo
{
    if(nodo == NULL) return;
    GeraNodosDOT(nodo->esq);
    //node10[label = "<esq> | 10 | <dir> "];
    cout << "node" << nodo->info << "[label = \"<esq> | " << nodo->info << " | <dir> \"]" <<endl;
    GeraNodosDOT(nodo->dir);
}

void ABP::GeraNodosDOT()//Chama a funcao geranodosDOr
{
    GeraNodosDOT(Raiz);
}
void ABP::GeraConexoesDOT()//Chama a funcao geraCOnexoesDOT
{
    GeraConexoesDOT(Raiz);
}
void ABP::GeraDOT() //Cria o arquivo para ser lido nos digrafos chamando todas funcoes construtoras de dot
{
    cout << "digraph g { \nnode [shape = record,height=.1];\n" << endl;
    GeraNodosDOT();
    cout << endl;
    GeraConexoesDOT();
    cout << "}" << endl;
}
// ************************************
void ABP::CaminhaPRE() //Chama a funcao para percorrer o caminho pre fixado
{
  cout << "Caminhamento Pré Fixado: ";
  CaminhaPRE(Raiz);
  cout << endl;
}
// ************************************
void ABP::CaminhaPRE(NodoABP *nodo)//Percorre o nodo usando o caminho pre fixado Ver slides arvores binarias de pesquisa
{
  if(nodo == NULL) return;
  cout << nodo->info << " ";
  CaminhaPRE(nodo->esq);
  CaminhaPRE(nodo->dir);  
}
// ************************************
void ABP::CaminhaPOS(NodoABP *nodo)//Percorre o nodo usando o caminho pos fixado. Ver slides arvores de pesquisa binarias
{
  if(nodo == NULL) return;
  CaminhaPOS(nodo->esq);
  CaminhaPOS(nodo->dir);  
  cout << nodo->info << " ";
}
// ************************************
void ABP::CaminhaPOS() //Chama a funcao Caminha Pos
{
  cout << "Caminhamento Pos Fixado: ";
  CaminhaPOS(Raiz);
  cout << endl;
}

void ABP::AplicaBalanceamento(NodoABP *auxGuia) //Faz o balanceamento usando AVL no nodo
{
  //Ler sobre https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
  NodoABP *auxP, *aux; // Cria um ponteiro auxiliar
  auxP = Raiz;//Faz ele apontar para a raiz
  while(1){ //Ira repetir os processos ate balancear a arvore
    aux = auxGuia;
    int somaEsq = 0, somaDir = 0; // Salva o tamanho da arvore
    somaEsq = ProfundidadeEsquerda(auxP) - 1;//Calcula o tamanho da arvore
    somaDir = ProfundidadeDireita(auxP) - 1; //Calcula o tamanho da arvore  
    cout << "Esq " << somaEsq << endl;
    cout << "Dir " << somaDir << endl;
    cout << "Dif " << abs(somaDir-somaEsq) << endl;      
    if(abs(somaDir - somaEsq) > 1){ //Vejo se elas estao desbalanceadas
      if(somaDir < somaEsq){ //Rotacao EE
          if(aux == getRaiz()){// Testa se e raiz e o aux sao iguais
              Raiz = aux->esq;              
              if(Raiz->dir == nullptr){
                 Raiz->dir = aux;
                 aux->esq = nullptr;
              }
              else{
                NodoABP *temp;
                temp = Raiz->dir;
                Raiz->dir = aux;
                aux->esq = temp;
              }   
              auxP = Raiz;
          }
          else{
             NodoABP *temp;
             temp = aux->esq;
             if(temp->dir == nullptr){
               temp->dir = aux;
               aux->esq = nullptr;
             }
             else{
               NodoABP *temp2;
               temp2 = temp->dir;
               temp->dir = aux;
               aux->esq = temp2;
             }
             auxP = temp;

          }
      }
      else{//Rotacao DD
          if(aux == getRaiz()){
            Raiz = aux->dir;
            if(Raiz->esq == nullptr){
              Raiz->esq = aux;
              aux->dir = nullptr;
            }
            else{
              NodoABP *temp;
              temp = Raiz->esq;
              Raiz->esq = aux;
              aux->dir = temp;
            }
            auxP = Raiz;
          }
          else{
            NodoABP *temp;
            temp = aux->dir;
            if(temp->esq == nullptr){
              temp->esq = aux;
              aux->dir = nullptr;
            }
            else{
              NodoABP *temp2;
              temp2 = temp->esq;
              temp->esq = aux;
              aux->dir = temp2;
            }
            auxP = temp;
          }
      
      }
    }
    else{
      break;
    }
    
  }
  
}

void ABP::AplicaBalanceamento(){

  AplicaBalanceamento(Raiz);

}
