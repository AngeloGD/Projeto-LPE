
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  int menu = 0, fila = 0, contfila = 0, op = 0, carrosatend = 0, escolha = 0;
  float preco, valorvendas = 0, litros = 0, tanque = 200, litrosvend = 0;

  struct Tcarro *carroFila;
  struct Tcarro *carroAtendido;

  FILE *arquivo;

  INTRO();

  do {
    printf("\nPor gentileza, informe o preço da gasolina:\nATENÇÃO: Utilize um "
           "ponto para definir o valor em centavos!!\n");
    scanf("%f", &preco);
    if (preco <= 0) {
      printf(RED "\nValor fornecido é ivalido.\n" WHT);
    }

  } while (preco <= 0);
  do {
    printf(
        "\nNeste momento informe a quantidade de carros que a fila suporta:\n");
    scanf("%d", &fila);
    if (fila <= 0) {
      printf(RED "\nValor fornecido é ivalido.\n" WHT);
    }
  } while (fila <= 0);

  carroFila = calloc(fila, sizeof(struct Tcarro));
  int tamanhoAtendido = 0;
  carroAtendido = calloc(tamanhoAtendido, sizeof(struct Tcarro));
  system("clear");

  while (menu != 5) {
    op = 0;
    printf("\nValor do combustível: R$ %.3f\n", preco);
    printf("Capacidade da fila: %d carros\n\n", fila);

    MENU();

    scanf("%d", &menu);

    switch (menu) {
    case (1):
      system("clear");
      printf("[1] Adicionar um carro na fila:\n\n");
      if (tanque != 0) {
        if (contfila < fila) {
          printf("Informe o modelo do carro: ");
          setbuf(stdin, NULL);
          fgets(carroFila[contfila].modelo, 20, stdin);
          carroFila[contfila]
              .modelo[strcspn(carroFila[contfila].modelo, "\n")] = 0;
          printf("Informe o ano de fabricação do carro: ");
          scanf("%d", &carroFila[contfila].ano);
          printf("Informe a cor do carro: ");
          setbuf(stdin, NULL);
          fgets(carroFila[contfila].cor, 10, stdin);
          carroFila[contfila].cor[strcspn(carroFila[contfila].cor, "\n")] = 0;
          printf(GRN "Carro adicionado.\n\n" WHT);
          contfila += 1;
        } else {
          printf(RED "Não é possível adicionar mais carros à fila.\n\n" WHT);
        }
        printf("%d carros na fila\n\n", contfila);
      } else
        printf(RED "Não há mais gasolina para abastecer novos "
                   "carros.\n\nZerando fila!\n\n" WHT);
      break;
    case (2):
      system("clear");
      printf("[2] Abastecimento:\n\n");
      if (tanque != 0) {
        if (contfila > 0) {
          printf("Restam %.2f litros de combustível.\n\n", tanque);
          printf("Informe a quantidade de litros para abastecer:\n");
          scanf("%f", &litros);
          system("clear");
          if (litros <= 0) {
            printf(RED "\nValor fornecido é ivalido.\n" WHT);
          } else if (litros > tanque) {
            while ((escolha != 1) && (escolha != 2)) {
              printf(RED
                     "Essa quantidade não está disponível no tanque.\n\n" WHT);
              printf("Deseja abastecer com o que resta no tanque? %.2f "
                     "Litros.\n\n",
                     tanque);
              printf(GRN "[1] SIM\n\n");
              printf(RED "[2] NÃO\n\n" WHT);
              scanf("%d", &escolha);
              system("clear");
              switch (escolha) {
              case (1):

                tanque = 0;
                litrosvend = 200 - tanque;
                tamanhoAtendido++;
                carroAtendido = realloc(
                    carroAtendido, tamanhoAtendido * sizeof(struct Tcarro));
                carroAtendido[carrosatend] = carroFila[0];
                carrosatend += 1;

                printf(GRN "Carro abastecido.\n\nReorganizando fila.\n\n" WHT);
                printf(RED "Não há mais gasolina no tanque\n\n" WHT);
                break;
              case (2):
                printf("Obrigado pela atenção e volte sempre!\n\n");
                break;
              default:
                INVALIDO();
                break;
              }
            }
            escolha = 0;
          } else {
            tanque -= litros;
            litrosvend = 200 - tanque;
            tamanhoAtendido++;
            carroAtendido =
                realloc(carroAtendido, tamanhoAtendido * sizeof(struct Tcarro));
            carroAtendido[carrosatend] = carroFila[0];
            carrosatend += 1;
            printf(GRN "Carro abastecido.\n\nReorganizando fila.\n\n" WHT);
            printf("Restam %.2f litros de combustível.\n\n", tanque);
          }
          for (int k = 0; k < contfila; k++) {
            carroFila[k] = carroFila[k + 1];
          }
          contfila -= 1;
        } else {
          printf(RED "Não há carros disponíveis para abastecer!\n\n" WHT);
        }
      } else {
        printf(RED "Não há combustível no tanque!\n\nZerando fila!\n\n" WHT);
      }
      break;
    case (3):
      system("clear");
      printf("[3] Exibir carros na fila de espera:\n\n");
      if (tanque != 0) {
        printf("%d carros ainda não foram abastecidos.\n\n", contfila);
        for (int k = 0; k < contfila; k++) {
          printf("\nCarro %d\n", (k + 1));
          printf("O modelo do carro é: %s\n", carroFila[k].modelo);
          printf("Cor do carro: %s\n", carroFila[k].cor);
          printf("Ano de fabricação: %d\n\n", carroFila[k].ano);
        }
      } else {
        printf(RED "Não há carros na fila!\n\n" WHT);
      }

      break;
    case (4):
      system("clear");

      while (op != 6) {

        RELATORIOS();

        scanf("%d", &op);
        switch (op) {
        case (1):
          system("clear");
          printf("[1] Quantidade de litros vendida:\n\n%.2f Litros.\n\n",
                 litrosvend);
          break;
        case (2):
          system("clear");
          valorvendas = (preco * litrosvend);
          printf("[2] Valor total arrecadado com as vendas:\n\nR$ %.2f\n\n",
                 valorvendas);
          break;
        case (3):
          system("clear");
          printf("[3] Quantidade de carros "
                 "atendidos:\n\n%d Carros.\n\n",
                 carrosatend);
          for (int k = 0; k < carrosatend; k++) {
            printf("Carro %d\n", k + 1);
            printf("O modelo do carro é: %s\n", carroAtendido[k].modelo);
            printf("Cor do carro: %s\n", carroAtendido[k].cor);
            printf("Ano de fabricação: %d\n\n", carroAtendido[k].ano);
          }

          break;
        case (4):
          system("clear");
          printf("[4] Quantidade de combustível restante no tanque:\n\n%.2f "
                 "Litros.\n\n",
                 tanque);
          break;
        case (5):
          system("clear");
          printf("[5] Gerar arquivo "
                 "para impressão com todas as informações de 1, 2, 3 e 4:\n\n");
          printf(" Quantidade de litros vendida: %.2f Litros.\n", litrosvend);
          valorvendas = (preco * litrosvend);
          printf(" Valor total arrecadado com as vendas: R$ %.2f\n",
                 valorvendas);
          printf(" Quantidade de carros "
                 "atendidos: %d Carros.\n",
                 carrosatend);
          printf(" Quantidade de combustível restante no tanque: %.2f "
                 "Litros.\n\n",
                 tanque);

          arquivo = fopen("arquivo.txt", "w");

          if (arquivo == NULL) {
            printf(RED "Arquivo não pode ser aberto!\n\n" WHT);
            exit(0);
          } else {
            fprintf(arquivo, "RELÁTORIOS:\n");
            fprintf(arquivo, " Quantidade de litros vendida: %.2f Litros.\n",
                    litrosvend);
            valorvendas = (preco * litrosvend);
            fprintf(arquivo, " Valor total arrecadado com as vendas: R$ %.2f\n",
                    valorvendas);
            fprintf(arquivo,
                    " Quantidade de carros "
                    "atendidos: %d Carros.\n",
                    carrosatend);
            fprintf(arquivo,
                    " Quantidade de combustível restante no tanque: %.2f "
                    "Litros.\n\n",
                    tanque);
            if (carrosatend > 0) {
              fprintf(arquivo, "Carros atendidos:\n\n");
              for (int k = 0; k < carrosatend; k++) {
                fprintf(arquivo, "Carro %d\n", k + 1);
                fprintf(arquivo, "O modelo do carro é: %s\n",
                        carroAtendido[k].modelo);
                fprintf(arquivo, "Cor do carro: %s\n", carroAtendido[k].cor);
                fprintf(arquivo, "Ano de fabricação: %d\n\n",
                        carroAtendido[k].ano);
              }
            }
          }
          fclose(arquivo);
          break;
        case (6):
          system("clear");
          printf("[6] Voltar ao menu anterior:\n\n");
          break;
        default:
          system("clear");
          INVALIDO();
          break;
        }
      }
      break;

    case (5):
      system("clear");
      printf("[5] Encerrando...\n\n");
      free(carroAtendido);
      free(carroFila);
      break;
    default:
      system("clear");
      INVALIDO();
      break;
    }
  }
  return 0;
}