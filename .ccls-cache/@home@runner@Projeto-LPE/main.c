#include <stdio.h>
#include <string.h>

#define TAM 20

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
  // int placa;
};

int main(void) {

  int menu = 0, fila = 0, contfila = 0, op = 0, litros = 0, tanque = 200,
      carrosatend = 0, litrosvend = 0, escolha = 0, i = 0, j = 0;
  float preco, valorvendas = 0;
  struct Tcarro carroFila[TAM];
  struct Tcarro carroAtendido[TAM];

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

  system("clear");

  while (menu != 5) {
    op = 0;

    printf("\n\nValor do combustível: R$ %.3f\n", preco);
    printf("Capacidade da fila: %d carros\n", fila);

    MENU();

    scanf("%d", &menu);

    switch (menu) {
    case (1):
      system("clear");
      if (contfila < fila) {
        printf("[1] Adicionar um carro na fila:\n\n");
        printf("Informe o modelo do carro: ");
        setbuf(stdin, NULL);
        fgets(carroFila[i].modelo, 20, stdin);
        carroFila[i].modelo[strcspn(carroFila[i].modelo, "\n")] = 0;
        printf("Informe o ano de fabricação do carro: ");
        scanf("%d", &carroFila[i].ano);
        // printf("Informe a placa do carro: ");
        // scanf("%d", &carroFila[i].placa);
        printf("Informe a cor do carro: ");
        setbuf(stdin, NULL);
        fgets(carroFila[i].cor, 10, stdin);
        carroFila[i].cor[strcspn(carroFila[i].cor, "\n")] = 0;
        printf(GRN "Carro adicionado.\n\n" WHT);
        contfila += 1;
        i += 1;
      } else {
        printf(RED "Não é possível adicionar mais carros à fila.\n\n" WHT);
      }
      printf("%d carros na fila\n\n", contfila);
      break;
    case (2):
      system("clear");
      printf("[2] Abastecimento:\n\n");
      if (tanque != 0) {
        if (contfila > 0) {
          printf("Restam %d litros de combustível.\n\n", tanque);
          printf("\nInforme a quantidade de litros para abastecer:\n");
          scanf("%d", &litros);
          system("clear");
          if (litros <= 0) {
            printf(RED "\nValor fornecido é ivalido.\n" WHT);
          } else if (litros > tanque) {
            while ((escolha != 1) && (escolha != 2)) {
              printf(
                  RED
                  "\nEssa quantidade não está disponível no tanque.\n\n" WHT);
              printf("\nDeseja abastecer com o que resta no tanque? %d "
                     "Litros.\n\n",
                     tanque);
              printf(GRN "\n[1] SIM\n\n");
              printf(RED "\n[2] NÃO\n\n" WHT);
              scanf("%d", &escolha);
              system("clear");
              switch (escolha) {
              case (1):
                contfila -= 1;
                tanque = 0;
                litrosvend = 200 - tanque;
                strcpy(carroAtendido[carrosatend].modelo,
                       carroFila[carrosatend].modelo);
                carroAtendido[carrosatend].ano = carroFila[carrosatend].ano;
                strcpy(carroAtendido[carrosatend].cor,
                       carroFila[carrosatend].cor);
                carrosatend += 1;

                printf(GRN
                       "\nCarro abastecido.\n\nReorganizando fila.\n\n" WHT);
                printf("\nNão há mais gasolina no tanque\n\n");
                break;
              case (2):
                contfila -= 1;
                carrosatend += 1;
                printf("\nObrigado pela atenção e volte sempre!\n\n");
                break;
              default:
                INVALIDO();
                break;
              }
            }
          } else {
            contfila -= 1;
            tanque -= litros;
            litrosvend = 200 - tanque;
            // strcpy(string_destino,string_origem);
            strcpy(carroAtendido[carrosatend].modelo,
                   carroFila[carrosatend].modelo);
            carroAtendido[carrosatend].ano = carroFila[carrosatend].ano;
            strcpy(carroAtendido[carrosatend].cor, carroFila[carrosatend].cor);

            carrosatend += 1;
            printf(GRN "Carro abastecido.\n\nReorganizando fila.\n\n" WHT);
            printf("Restam %d litros de combustível.\n\n", tanque);
          }
        } else {
          printf(RED "\nNão há carros disponíveis para abastecer!\n\n" WHT);
        }
      } else {
        printf(RED "\nNão há combustível no tanque!\n\n" WHT);
      }
      break;
    case (3):
      system("clear");
      printf("[3] Exibir carros na fila de espera:\n\n");
      printf("%d carros ainda não foram abastecidos.\n\n", contfila);
      j = carrosatend;
      while (j < i) {
        printf("\n\nCarro %d", (j - carrosatend + 1));
        printf("\nO modelo do carro é: %s ", carroFila[j].modelo);
        printf("\nCor do carro: %s ", carroFila[j].cor);
        printf("\nAno de fabricação: %d ", carroFila[j].ano);
        // printf("\nPlaca do carro: %d ", carroFila[j].placa);
        j += 1;
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
          printf("\n[1] Quantidade de litros vendida:\n\n%d Litros.\n\n",
                 litrosvend);
          break;
        case (2):
          system("clear");
          valorvendas = (preco * litrosvend);
          printf("\n[2] Valor total arrecadado com as vendas:\n\nR$ %.2f\n\n",
                 valorvendas);
          break;
        case (3):
          system("clear");
          printf("\n[3] Quantidade de carros "
                 "atendidos:\n\n%d Carros.\n\n",
                 carrosatend);
          j = 0;
          while (j < carrosatend) {
            printf("\n\nCarro %d", j + 1);
            printf("\nO modelo do carro é: %s ", carroFila[j].modelo);
            printf("\nCor do carro: %s ", carroFila[j].cor);
            printf("\nAno de fabricação: %d ", carroFila[j].ano);
            // printf("\nPlaca do carro: %d ", carroFila[j].placa);
            j += 1;
          }

          break;
        case (4):
          system("clear");
          printf("\n[4] Quantidade de combustível restante no tanque:\n\n%d "
                 "Litros.\n\n",
                 tanque);
          break;
        case (5):
          system("clear");
          printf("\n[5] Gerar arquivo "
                 "para impressão com todas as informações de 1, 2, 3 e 4:\n\n");
          printf("\n Quantidade de litros vendida: %d Litros.\n", litrosvend);
          valorvendas = (preco * litrosvend);
          printf("\n Valor total arrecadado com as vendas: R$ %.2f\n",
                 valorvendas);
          printf("\n Quantidade de carros "
                 "atendidos: %d Carros.\n",
                 carrosatend);
          printf("\n Quantidade de combustível restante no tanque: %d "
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
      printf("[5] Encerrar...\n\n");
      break;
    default:
      system("clear");
      INVALIDO();
      break;
    }
  }
  return 0;
}
