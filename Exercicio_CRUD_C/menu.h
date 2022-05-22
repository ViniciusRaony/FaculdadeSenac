#include <stdio.h>

int menu(){
  int opcao = 0;
  int c;

  printf("\n Menu CRUD de PRODUTOS \n");
  printf("\n 1 - Criar cadastro");
  printf("\n 2 - Ler cadastro");
  printf("\n 3 - Atualizar cadastro");
  printf("\n 4 - Apagar cadastro");
  printf("\n 5 - Sair");
  printf("\n Sua opcao: ");
  scanf("%d", &opcao);
  
  /* FIX para o fgets de createCadastro capturando enter do teclado - Pula todos os caracteres até que a próxima nova linha ou EOF seja alcançada */
  while((c= getchar()) != '\n' && c != EOF);

  return opcao;
}