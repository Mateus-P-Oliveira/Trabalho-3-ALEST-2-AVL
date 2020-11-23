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
int ABP::Altura(NodoABP *n){
  if(n == nullptr) return 0;
  return n->altura;
}
// ************************************
NodoABP* ABP::insere(NodoABP *nodo, int n)//Insere o valor do nodo na arvore e decide para qual lado ele ira inserir de acordo com o tamnho de n
{
  int recebe;
  if (nodo == NULL) { // encontrou o local para inserir
    NodoABP *aux;
    aux = new NodoABP(n);
    return aux;
  }
  else {
          if (n <= nodo->info)
          {
            nodo->esq =  insere(nodo->esq, n);
            
          }
          else
          {
            nodo->dir = insere(nodo->dir, n);
          }
    }
    recebe = CalculaProfundidade(nodo);
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
      // PINHO
    n->alturaEsq = alturaEsq;
    n->alturaDir = alturaDir;

    return 1 + max (alturaEsq, alturaDir);//Max retorna o valor mais alto entre esq e direita, caso sejam iguais ele retorna esquerda
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
void ABP::GeraConexoesDOT(NodoABP *nodo)
{
    if(nodo == NULL) return;
    
    GeraConexoesDOT(nodo->esq);
    //   "nodeA":esq -> "nodeB" [color="0.650 0.700 0.700"]
    if (nodo->esq)
        cout << "\"node" << nodo->info << "\":esq -> \"node" << nodo->esq->info << "\" " <<
        "[label = " << nodo->alturaEsq << "]" << endl;
    GeraConexoesDOT(nodo->dir);
    //   "nodeA":dir -> "nodeB";
    if (nodo->dir)
        cout << "\"node" << nodo->info << "\":dir -> \"node" << nodo->dir->info << "\" " <<
        "[label = " << nodo->alturaDir << "]" <<endl;
    
    /*   if (nodo->pai)   //"node2":dir -> "node6" [label = 1]
     cout << "\"node" << nodo->info << "\" -> \"node" << nodo->pai->info << "\" " <<
     "[color=\"0.650 0.700 0.700\"]"<< endl;
     */
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
// ---------------------------------------------------------------------------------------------------------------------------------------------

// ************************************ // So irei fazer as rotacoes nesse caso 
//Em todos casos a e pai de b 
NodoABP* ABP::RotacionaEE(NodoABP *a, NodoABP *b)// A nodo desbalanceado e B nodo a esq dele com quem ira trocar //Rotacao Esquerda-Esquerda
{  
   if (b->dir == nullptr)
  {
    // Caso B nao tenha filho
    b->dir = a; // A vira a raiz a direita de b
    a->esq = nullptr; //A deixa sua raiz esquerda apontando para o vazio
    if(a != getRaiz()) a->pai->esq = b; // Faz o pai de a apontar para a esq     
    
    b->pai = a->pai;//Define o pai do nodo b como sendo o pai de a
    a->pai = b; //Define o pai do nodo a
    //cout << a->pai->info << endl;
  }
  else
  { //Caso B tenha um filho
    NodoABP *filho;
    filho = b->dir;
    b->dir = a;
    a->esq = filho;
    if(a != getRaiz())
        a->pai->esq = b; // Faz o pai de a apontar para a esq
    b->pai = a->pai;
    a->pai = b;
  }
  if(a == getRaiz())
        Raiz = b; // B que e o filho vira a nova raiz
  AlteraAltura(a); //Recalcula a altura do nodo
  AlteraAltura(b); //Recalcula a altura do nodo
  
  return b;//Retorna um ponteiro para B que ira indicar onde devo continuar com meu ponteiro de movimentacao
}
// ************************************
NodoABP* ABP::RotacionaDD(NodoABP *a, NodoABP *b){// A nodo desbalanceado e B nodo a dir dele com quem ira trocar // Rotacao Direita-Direita

   if(b->esq == nullptr){//Caso B nao tenha um filho
    b->esq = a;
    a->dir = nullptr;
    if(a != getRaiz()) a->pai->dir = b; //Faz o pai apontar para o novo filho
    b->pai = a->pai;
    a->pai = b;
  }
  else{//Caso b tenha um filho
    NodoABP *filho;
    filho = b->esq;
    b->esq = a;
    a->dir = filho;
    if(a != getRaiz()) a->pai->dir = b;// Faz o pai apontar para o novo filho
    b->pai = a->pai;
    a->pai = b;
  }
  if(a == getRaiz()) Raiz = b;//Caso A seja a raiz o B vira a raiz
  AlteraAltura(a);// Recalcula a altura do nodo
  AlteraAltura(b);// Recalcula a altura do nodo
  
  return b;//Retorna um ponteiro para B que ira indicar onde devo continuar com meu ponteiro de movimentacao
}
// ************************************
NodoABP* ABP::RotacionaED(NodoABP *a, NodoABP *b){//Rotacao Esquerda-Direita
  NodoABP *c, *y; //Nodo filho de b e nodo que sera retornado com a nova arvore
  c = RotacionaDD(b,b->dir); //RotacaoDD na subarvore a esquerda
  y = RotacionaEE(a,c); //RotacaoEE em toda arvore

  return y;//Retorna o ponteiro para a nova arvore
}
// ************************************
NodoABP* ABP::RotacionaDE(NodoABP *a, NodoABP *b){//Rotacao Direita-Esquerda
  NodoABP *c, *y; //Nodo filho de b e nodo que sera retornado com a nova arvore

  c =  RotacionaEE(b,b->esq);//Rotacao EE na subarvore a direita
  y = RotacionaDD(a,c);//RotacaoDD em toda arvore

  return y;
}
// ************************************

void ABP::AlteraAltura(NodoABP *nodo){//Altera a altura dos Nodos
  //cout << nodo->info << " " << nodo->altura << endl;
  //nodo->altura = 1 + max(Altura(nodo->esq),Altura(nodo->dir));
  int recebe;
  recebe = CalculaProfundidade(nodo);
  //cout << nodo->info << " " << nodo->altura << endl;
}

void ABP::CriaFilho(){//Chama a funcao que cria os filhos
  CriaFilho(Raiz);
}

void ABP::CriaFilho(NodoABP *nodo){//Cria a relacao pai filho
  if(nodo == NULL) return;
  if(nodo->esq != nullptr) nodo->esq->pai = nodo;
  if(nodo->dir != nullptr) nodo->dir->pai = nodo;  
  CriaFilho(nodo->esq);
  CriaFilho(nodo->dir); 
}

void ABP::AplicaBalanceamento(NodoABP *nodo){//Chama a funcao aplica balanceamento
  CriaFilho(); // Cria os filhos para os ponteiros nao se perderem
  BalanceiaNodo(nodo);
  CriaFilho(); 
  AlteraAltura(Raiz); //Altera altura apos aplicar o balanceamento
}

int ABP::FatorBalanceamento(NodoABP *n){//Aplica o fator balanceamento so contando as arvores que contam
  if(n == nullptr) return 0;
  return n->alturaEsq - n->alturaDir;
  }  
  
// *************************************
void ABP::BalanceiaNodo(NodoABP *nodo)//Percorre o nodo usando o caminho pos fixado. Ver slides arvores de pesquisa binarias
{   
  
  if(FatorBalanceamento(nodo) > 1 && nodo->esq->alturaEsq > nodo->esq->alturaDir ){ //EE
    //cout << "Rotacao EE" << endl;
    //nodo->imprime();
    nodo = RotacionaEE(nodo,nodo->esq);
    //cout << "Ponteiro " << endl;
    //nodo->imprime();
    
  }
  if(FatorBalanceamento(nodo) < -1 && nodo->dir->alturaDir > nodo->dir->alturaEsq ){ //DD
    //cout << "Rotacao DD" << endl;
    //nodo->imprime();
    nodo = RotacionaDD(nodo,nodo->dir);
    //cout << "Ponteiro " << endl;
    //nodo->imprime();
  }
  if(FatorBalanceamento(nodo) > 1 && nodo->esq->alturaEsq < nodo->esq->alturaDir){//ED
    //cout << "Rotacao ED" << endl;
    //nodo->imprime();
    nodo = RotacionaED(nodo,nodo->esq);
    //cout << "Ponteiro " << endl;
    //nodo->imprime();
  }
  if(FatorBalanceamento(nodo) < -1 && nodo->dir->alturaDir < nodo->dir->alturaEsq){ //DE
    //cout << "Rotacao DE" << endl;
    //nodo->imprime();
    nodo = RotacionaDE(nodo,nodo->dir);
    //cout << "Ponteiro " << endl;
    //nodo->imprime();
  }
  /*if(FatorBalanceamento(nodo) > 1 && nodo->esq->alturaEsq == nodo->esq->alturaDir){
        cout << "Rotacao EE" << endl;
        nodo = RotacionaEE(nodo,nodo->esq);

  }
  if(FatorBalanceamento(nodo) < -1 && nodo->dir->alturaDir == nodo->dir->alturaEsq ){ //DD
        cout << "Rotacao DD " << endl;
        nodo = RotacionaDD(nodo,nodo->dir);
  }*/ 
}

void ABP::BalanceiaArvore(){
  
  CaminhoArvore(Raiz);
  //CaminhoArvore(Raiz);
  //Caso sobre algo desbalanceado por nao cair nos if anteriores

  
}

void ABP::CaminhoArvore(NodoABP *aux){//Move pela Arvore usando o caminhamento POS

  if(aux == NULL) return;

  CaminhoArvore(aux->esq);
  CaminhoArvore(aux->dir); 
 
  if(abs(FatorBalanceamento(aux)) > 1) AplicaBalanceamento(aux);
  //GeraDOT();

}

void ABP::Caminho(NodoABP *aux){ //Nao usar 
  if(aux == NULL) return;
        if(abs(FatorBalanceamento(aux)) > 1) AplicaBalanceamento(aux);

  CaminhoArvore(aux->esq);\

  CaminhoArvore(aux->dir); 
 
}

void ABP::MovendoPelaArvore(){//Possui erros na movimentacao a direita
  NodoABP *guia;
  guia = Raiz;
  CriaFilho();
   while (guia->esq != nullptr)//Move Guia ate o ultimo valor da subarvore a esquerda
    {
      guia = guia->esq;
    }
    while(guia->pai != nullptr){      

      if(abs(FatorBalanceamento(guia)) > 1){
       // cout << "Nodo a ser balanceado " << endl;
        //guia->imprime();
        //cout << "Fator Balanceamento " << endl;
        //cout << FatorBalanceamento(guia) << endl;
        AplicaBalanceamento(guia);
        
        //GeraDOT();
      } 
      guia = guia->pai;
    }
    cout << "Troca" << endl;
    //Balanceamento nao ocorre quando for igual a altura das sub arvores
  while(guia != nullptr){
    
    if(abs(FatorBalanceamento(guia)) > 1){
      //cout << "Nodo a ser balanceado " << endl;
        //guia->imprime();
         //cout << "Fator Balanceamento " << endl;
        //cout << FatorBalanceamento(guia) << endl;
      AplicaBalanceamento(guia);
    } 
    guia = guia->dir;
  }


}