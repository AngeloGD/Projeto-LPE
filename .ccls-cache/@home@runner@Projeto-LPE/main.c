#include <stdio.h>

int main(void) {

  int menu = 0, fila, op = 0;
  float preco;

  printf("\n\tAutor: Angelo Gabriel Debarba\n");
  printf("\nDESCRIÇÃO:\n\nEsse programa tem como base gerenciar as informações "
         "de um posto de gasolina que contém apenas uma bomba e um tipo de "
         "combustível.\n");

  printf("\nPor gentileza, informe o preço da gasolina:\nATENÇÃO: Utilize um "
         "ponto para definir o valor em centavos!!\n");
  scanf("%f", &preco);

  printf(
      "\nNeste momento informe a quantidade de carros que a fila suporta:\n");
  scanf("%d", &fila);
  system("clear");
  while (menu != 5) {
    op = 0;
    printf("\t\t\tMENU PRINCIPAL\n\n");
    printf(" Escolha uma opção:\n\n[1] Adicionar um carro na fila.\n\n[2] "
           "Abastecimento.\n\n[3] Exibir carros na fila de espera.\n\n[4] "
           "Relatórios.\n\n[5] Encerrar.\n\n");
    scanf("%d", &menu);

    switch (menu) {
    case (1):
      printf("Opção escolhida:\n\n");
      printf("[1] Adicionar um carro na fila:\n\n");
      printf("Carro adicionado.\n\n");
      break;
    case (2):
      printf("Opção escolhida:\n\n");
      printf("[2] Abastecimento:\n\n");
      printf("Primeiro carro abastecido.\n\nReorganizando fila.\n\n");
      break;
    case (3):
      printf("Opção escolhida:\n\n");
      printf("[3] Exibir carros na fila de espera:\n\n");
      printf("?? carros ainda não foram abastecidos.\n\n");
      break;
    case (4):
      printf("\n\nOpção escolhida:\n\n");
      printf("[4] Relatórios:\n\n\n");

      while (op != 6) {
        printf(
            " Escolha uma opção:\n\n[1] Quantidade de litros vendida.\n\n[2] "
            "Valor total arrecadado com as vendas.\n\n[3] Quantidade de carros "
            "atendidos.\n\n[4] "
            "Quantidade de combustível restante no tanque.\n\n[5] Gerar "
            "arquivo "
            "para impressão (com todas as informações de 1, 2, 3 e 4).\n\n[6] "
            "voltar ao menu anterior.\n\n");
        scanf("%d", &op);
        switch (op) {
        case (1):
          printf("\nQuantidade de litros vendida:\n\n?? Litros.\n\n");
          break;
        case (2):
          printf(
              "\nValor total arrecadado com as vendas:\n\n?? Arrecadado.\n\n");
          break;
        case (3):
          printf("\nQuantidade de carros "
                 "atendidos:\n\n?? Carros.\n\n");
          break;
        case (4):
          printf("\nQuantidade de combustível restante no tanque:\n\n?? "
                 "Litros.\n\n");
          break;
        case (5):
          printf("\nGerar arquivo "
                 "para impressão com todas as informações de 1, 2, 3 e 4:\n\n");
          break;
        case (6):
          printf("\nvoltar ao menu anterior:\n\n");
          break;
        default:
          printf("\nOpção invalida.\n\n");
          break;
        }
      }
      break;

    case (5):
      printf("\nOpção escolhida:\n\n");
      printf("[5] Encerrar:\n\n");
      break;
    default:
      printf("Opção invalida.\n\n");
      break;
    }
    getchar();
  }
  return 0;
}