#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "menu.h"
#define TAMVET 20



typedef struct { //struct de Produto e seus atributos
  char nome[40];
  int idCodigo;
  double peso;
  int qtd;
  float valor;
} Produto;

Produto produto[20]; //declarando tamanho de vetor

/* ------------------------------- FUNÇÃO CRIAR CADASTRO ------------------------------- */
void createCadastro (){
  int i = 0;
  printf("\n####### CADASTRAR PRODUTO ########\n\n");
  
  for(i = 0 ; i < TAMVET; i++) {
    if (produto[i].idCodigo == 0) {
      printf("Insira nome: ");
      fgets(produto[i].nome, 40, stdin);
      printf("Insira código: ");
      scanf("%d", &produto[i].idCodigo);
      printf("Insira peso (kg): ");
      scanf("%lf", &produto[i].peso);
      printf("Insira quantidade: ");
      scanf("%d", &produto[i].qtd);
      printf("Insira valor: ");
      scanf("%f", &produto[i].valor);
      return;
    } 
  }
  printf("Sem espaço para cadastro\nRetornando para o menu...\n");
  return;
}

/* ------------------------------- FUNÇÃO LER CADASTRO ------------------------------- */
void readCadastro () {
  int j= 0;

  if (produto[0].idCodigo == 0) { //verificar se está vazio antes de perguntar ao usuário
    printf("\nNenhum produto cadastrado na base de dados\nRetornando para o menu...\n");
    return;
  }  

  for(j = 0 ; j < TAMVET; j++) {
    if(produto[j].idCodigo == 0) {
      break;
    }
    printf("\nPRODUTO %d\n", j+1);
    printf("Nome................ %s", produto[j].nome);
    printf("Codigo.............. %d\n", produto[j].idCodigo);
    printf("Peso................ %.2lf kg\n", produto[j].peso);
    printf("Quantidade.......... %d\n", produto[j].qtd);
    printf("Valor............... R$ %.2f\n", produto[j].valor);
 }
  return;
}
/* ------------------------------- FUNÇÃO ATUALIZAR CADASTRO ------------------------------- */
void updateCadastro() {
  int posicaoUpdate = 0, c;

  if (produto[0].idCodigo == 0) { //verificar se está vazio antes de perguntar ao usuário
    printf("\nNenhum produto cadastrado na base de dados\nRetornando para o menu...\n");
    return;
  }  

  printf("\n####### ATUALIZAR PRODUTO ########\n\n");
  printf("Digite qual produto deseja atualizar?\n");
  scanf("%d", &posicaoUpdate);
  while((c= getchar()) != '\n' && c != EOF);  // FIX para o fgets de createCadastro capturando enter do teclado
  printf("Insira nome: ");
  fgets(produto[posicaoUpdate-1].nome, 40, stdin);
  printf("Insira código: ");
  scanf("%d", &produto[posicaoUpdate-1].idCodigo);
  printf("Insira peso: ");
  scanf("%lf", &produto[posicaoUpdate-1].peso);
  printf("Insira quantidade: ");
  scanf("%d", &produto[posicaoUpdate-1].qtd);
  printf("Insira valor: ");
  scanf("%f", &produto[posicaoUpdate-1].valor);
  return;
}

/* ------------------------------- FUNÇÃO DELETAR CADASTRO ------------------------------- */
void deleteCadastro() {
  int posicaoDeletar = 0, k=0;

  if (produto[0].idCodigo == 0) { //verificar se está vazio antes de perguntar ao usuário
    printf("\nNenhum produto cadastrado na base de dados\nRetornando para o menu...\n");
    return;
  }  

  printf("\n####### DELETAR PRODUTO ########\n\n");
  printf("Qual produto deseja excluir?\n");
  scanf("%d", &posicaoDeletar);
  
  for (k = posicaoDeletar-1 ; k < TAMVET ; k++){
      produto[k] = produto[k + 1];
      }
  return;
}

/* ------------------------------- MAIN - PROGRAMA ------------------------------- */
int main(void) {

int opcao = 0;

  // Loop infinito, para reexibir MENU
  while(1) {
     
    opcao = menu();
    
    switch(opcao) {
      case 1: createCadastro();
              break;
      case 2: readCadastro();
              break;
      case 3: updateCadastro();
              break;
      case 4: deleteCadastro();
              break;
      case 5: printf("\nEncerrando programa...");
              exit(0);
              break;
      default: 
        printf("\nOpcão inválida\n");
    }
       
  }
  
  return 0;

}