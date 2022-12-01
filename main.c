
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

void MENU() {
  printf(BLU "\n\t\t\tMENU PRINCIPAL\n\n");
  printf(" Escolha uma opção:\n\n[1] Adicionar um carro na fila.\n\n[2] "
         "Abastecimento.\n\n[3] Exibir carros na fila de espera.\n\n[4] "
         "Relatórios.\n\n[5] Encerrar.\n\n" WHT);
}

void RELATORIOS() {
  printf(BLU "\n\n\t\t\tRelatórios:\n\n");
  printf(" Escolha uma opção:\n\n[1] Quantidade de litros vendida.\n\n[2] "
         "Valor total arrecadado com as vendas.\n\n[3] Quantidade de carros "
         "atendidos.\n\n[4] "
         "Quantidade de combustível restante no tanque.\n\n[5] Gerar "
         "arquivo "
         "para impressão (com todas as informações de 1, 2, 3 e 4).\n\n[6] "
         "voltar ao menu anterior.\n\n" WHT);
}

void INTRO() {
  printf(CYN "\n\tAutor: Angelo Gabriel Debarba\n");
  printf("\nDESCRIÇÃO:\n\nEsse programa tem como base gerenciar as informações "
         "de um posto de gasolina que contém apenas uma bomba e um tipo de "
         "combustível.\n" WHT);
}

void INVALIDO() { printf(RED "\nOPÇÃO INVALIDA!\n\n" WHT); }

struct Tcarro {
  char modelo[20];
  char cor[20];
  int ano;
};

int main(void) {

  int menu = 0, fila = 0, contfila = 0, op = 0, litros = 0, tanque = 200,
      carrosatend = 0, litrosvend = 0, escolha = 0, i = 0, j = 0;
  float preco, valorvendas = 0;

  struct Tcarro *carroFila;

  struct Tcarro *carroAtendido;

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
  int tamanhoAtendido = 1;
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
      if (tanque != 0) {
        if (contfila < fila) {
          printf("[1] Adicionar um carro na fila:\n\n");
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
          // i += 1;
        } else {
          printf(RED "Não é possível adicionar mais carros à fila.\n\n" WHT);
        }
        printf("%d carros na fila\n\n", contfila);
      } else
        printf(RED "Não há mais gasolina para abastecer novos carros.\n\n" WHT);
      break;
    case (2):
      system("clear");
      printf("[2] Abastecimento:\n\n");
      if (tanque != 0) {
        if (contfila > 0) {
          printf("Restam %d litros de combustível.\n\n", tanque);
          printf("Informe a quantidade de litros para abastecer:\n");
          scanf("%d", &litros);
          system("clear");
          if (litros <= 0) {
            printf(RED "\nValor fornecido é ivalido.\n" WHT);
          } else if (litros > tanque) {
            while ((escolha != 1) && (escolha != 2)) {
              printf(RED
                     "Essa quantidade não está disponível no tanque.\n\n" WHT);
              printf("Deseja abastecer com o que resta no tanque? %d "
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
                // strcpy(carroAtendido[carrosatend].modelo,carroFila[carrosatend].modelo);
                // carroAtendido[carrosatend].ano = carroFila[carrosatend].ano;
                // strcpy(carroAtendido[carrosatend].cor,carroFila[carrosatend].cor);
                carrosatend += 1;

                for (int k = 0; k < contfila; k++) {
                  carroFila[k] = carroFila[k + 1];
                }
                contfila -= 1;
                // i -= 1;
                printf(GRN "Carro abastecido.\n\nReorganizando fila.\n\n" WHT);
                printf("Não há mais gasolina no tanque\n\n");
                break;
              case (2):
                for (int k = 0; k < contfila; k++) {
                  carroFila[k] = carroFila[k + 1];
                }
                // i -= 1;
                contfila -= 1;
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
            // strcpy(string_destino,string_origem);
            tamanhoAtendido++;
            carroAtendido =
                realloc(carroAtendido, tamanhoAtendido * sizeof(struct Tcarro));
            carroAtendido[carrosatend] = carroFila[0];
            // strcpy(carroAtendido[carrosatend].modelo,carroFila[carrosatend].modelo);
            // carroAtendido[carrosatend].ano = carroFila[carrosatend].ano;
            // strcpy(carroAtendido[carrosatend].cor,
            // carroFila[carrosatend].cor);
            carrosatend += 1;
            printf(GRN "Carro abastecido.\n\nReorganizando fila.\n\n" WHT);
            printf("Restam %d litros de combustível.\n\n", tanque);
            for (int k = 0; k < contfila; k++) {
              carroFila[k] = carroFila[k + 1];
            }
            contfila -= 1;
          }
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
        // j = carrosatend;
        // while (j < i) {
        // j += 1;
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
          printf("[1] Quantidade de litros vendida:\n\n%d Litros.\n\n",
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
          // j = 0;
          // while (j < carrosatend) {
          // j += 1;
          for (int k = 0; k < carrosatend; k++) {
            printf("Carro %d\n", k + 1);
            printf("O modelo do carro é: %s\n", carroAtendido[k].modelo);
            printf("Cor do carro: %s\n", carroAtendido[k].cor);
            printf("Ano de fabricação: %d\n\n", carroAtendido[k].ano);
          }

          break;
        case (4):
          system("clear");
          printf("[4] Quantidade de combustível restante no tanque:\n\n%d "
                 "Litros.\n\n",
                 tanque);
          break;
        case (5):
          system("clear");
          printf("[5] Gerar arquivo "
                 "para impressão com todas as informações de 1, 2, 3 e 4:\n\n");
          printf(" Quantidade de litros vendida: %d Litros.\n", litrosvend);
          valorvendas = (preco * litrosvend);
          printf(" Valor total arrecadado com as vendas: R$ %.2f\n",
                 valorvendas);
          printf(" Quantidade de carros "
                 "atendidos: %d Carros.\n",
                 carrosatend);
          printf(" Quantidade de combustível restante no tanque: %d "
                 "Litros.\n\n",
                 tanque);
          break;
        case (6):
          system("clear");
          printf("\n[6] Voltar ao menu anterior:\n\n");
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