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
