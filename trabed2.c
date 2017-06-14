#include <stdio.h>
#include <stdlib.h>

const int t = 2;

typedef struct arvB{
  int nchaves;
  int folha;
  int* chave;
  int narqs;
  char** nomeArq;
}TAB;


void cria(char*arq, int t){
  FILE * fp = fopen(arq, "wb");
  if(!fp) exit(1);
  TAB* novo = (TAB*)malloc(sizeof(TAB));
  novo->nchaves = 0;
  novo->chave =(int*)malloc(sizeof(int*)*((t*2)-1));
  novo->folha=1;
  novo->narqs = 0;
  novo->nomeArq = (char**)malloc(sizeof(char**)*15); //aloca array de string com 15 caracteres
  fwrite(&novo, sizeof(TAB), 1, fp);
  fclose(fp);
}


void imprime(char*arq){
  FILE * fp = fopen(arq, "rb");
  if(!fp) exit(1);
  TAB*aux;
  fseek(fp, 0, SEEK_SET);
  fread(&aux, sizeof(TAB), 1, fp);
  if(aux){
    if(aux->narqs > 0){
      int j;
      for(j = 0; j<aux->narqs; j++){ //percorre o vetor de nome de arquivo e chama o imprime
        imprime(aux->nomeArq[j]);
      }
    }
    int i;
    if(aux->nchaves == 0){
      printf("%s\n", "Está vazio!" );
      exit(1);
    }
    if(aux->nchaves > 0){
      for(i = 0; i<aux->nchaves;i++){
        printf("%d\n", aux->chave[i]);
      }
    }
  }
  fclose(fp);
}

int main(){
  cria("ata.dat", t);
  int teclado;
  printf("%s\n", "Aperte 0 para sair" );
  printf("%s\n", "Aperte 1 para imprimir");
  printf("%s\n", "Aperte 2 para inserir" );
  printf("%s\n", "Aperte 3 para remover");
  printf("%s\n", "Aperte 4 para buscar");
  while(teclado != 0){
    scanf("%d", &teclado);
    if(teclado == 0) return -1;
    if(teclado == 1) imprime("ata.dat");
    /*if(teclado == 2) insere(*args);
    if(teclado == 3 ) remove(*args);
    if(teclado == 4) busca(*args);
    */
  }
}
