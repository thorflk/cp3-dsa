#include <stdio.h>
#include <string.h>
 
#define MAX_OPERACOES 3
#define TAM_TIPO      20
 
void  exibirMenu(void);
void  consultarSaldo(float saldo);
float realizarDeposito(float saldo, char tipos[][TAM_TIPO], float valores[], int *totalOperacoes);
float realizarSaque(float saldo, char tipos[][TAM_TIPO], float valores[], int *totalOperacoes);
void  registrarOperacao(char tipos[][TAM_TIPO], float valores[], int *totalOperacoes, char tipo[], float valor);
void  exibirExtrato(char tipos[][TAM_TIPO], float valores[], int totalOperacoes, float saldo);
void  pausar(void);
void  limparBuffer(void);
 
int main() {
    float saldo = 500.00f;
    int   opcao;
    int   totalOperacoes = 0;
    int   i;
 
    char  tipos[MAX_OPERACOES][TAM_TIPO];
    float valores[MAX_OPERACOES];
 
    for (i = 0; i < MAX_OPERACOES; i++) {
        tipos[i][0] = '\0';
        valores[i]  = 0.0f;
    }
 
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
 
        switch (opcao) {
            case 1: consultarSaldo(saldo);                                          break;
            case 2: saldo = realizarSaque(saldo, tipos, valores, &totalOperacoes);  break;
            case 3: saldo = realizarDeposito(saldo, tipos, valores, &totalOperacoes); break;
            case 4: exibirExtrato(tipos, valores, totalOperacoes, saldo);           break;
            case 0: printf("\nObrigado por usar nosso ATM!\n");                     break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    } while (opcao != 0);
 
    return 0;
}
 
void exibirMenu(void) {
    printf("\n==============================\n");
    printf("       CAIXA ELETRONICO       \n");
    printf("==============================\n");
    printf("1 - Consultar saldo\n");
    printf("2 - Realizar saque\n");
    printf("3 - Realizar deposito\n");
    printf("4 - Consultar extrato\n");
    printf("0 - Sair\n");
    printf("==============================\n");
    printf("Escolha uma opcao: ");
}

void consultarSaldo(float saldo) {
    printf("\n--------- SALDO ATUAL ---------\n");
    printf("Saldo disponivel: R$ %.2f\n", saldo);
    printf("-------------------------------\n");
    pausar();
}



void pausar(void) {
    printf("\nPressione Enter para continuar...");
    getchar();
}




void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta o caractere */
    }
}