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

float realizarDeposito(float saldo, char tipos[][TAM_TIPO], float valores[], int *totalOperacoes) {
    float valor;

    printf("\nDigite o valor do deposito: R$ ");
    scanf("%f", &valor);
    limparBuffer();

    if (valor > 0.0f) {
        saldo += valor;
        registrarOperacao(tipos, valores, totalOperacoes, "Deposito", valor);
        printf("\nDeposito realizado com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", saldo);
    } else {
        printf("\nValor invalido! O deposito deve ser maior que zero.\n");
    }

    pausar();
    return saldo;
}

float realizarSaque(float saldo, char tipos[][TAM_TIPO], float valores[], int *totalOperacoes) {
    float valor;
    float limiteSaque = 1000.00f;

    printf("\nDigite o valor do saque: R$ ");
    scanf("%f", &valor);
    limparBuffer();

    if (valor <= 0.0f) {
        printf("\nValor invalido! O saque deve ser maior que zero.\n");
    } else if (valor > limiteSaque) {
        printf("\nSaque negado! Limite por saque: R$ %.2f\n", limiteSaque);
    } else if (valor > saldo) {
        printf("\nSaque negado! Saldo insuficiente.\n");
    } else {
        saldo -= valor;
        registrarOperacao(tipos, valores, totalOperacoes, "Saque", valor);
        printf("\nSaque realizado com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", saldo);
    }

pausar();
return saldo; 
}    

void registrarOperacao(char tipos[][TAM_TIPO], float valores[], int *totalOperacoes, char tipo[], float valor) {
    int i;

    if (*totalOperacoes < MAX_OPERACOES) {
        strcpy(tipos[*totalOperacoes], tipo);
        valores[*totalOperacoes] = valor;
        (*totalOperacoes)++;
    } else {
        for (i = 0; i < MAX_OPERACOES - 1; i++) {
            strcpy(tipos[i], tipos[i + 1]); 
            valores[i] = valores[i + 1];
        }
        strcpy(tipos[MAX_OPERACOES - 1], tipo);
        valores[MAX_OPERACOES - 1] = valor;
    }
}

void exibirExtrato(char tipos[][TAM_TIPO], float valores[], int totalOperacoes, float saldo) {
    int i;

    printf("\n----------- EXTRATO -----------\n");

    if (totalOperacoes == 0) {
        printf("Nenhuma operacao realizada.\n");
    } else {
        /* Semana 05: for de 0 ate totalOperacoes-1, usando indice como posicao no vetor */
        for (i = 0; i < totalOperacoes; i++) {
            printf("%d - %s: R$ %.2f\n", i + 1, tipos[i], valores[i]);
        }
    }

    printf("-------------------------------\n");
    printf("Saldo atual: R$ %.2f\n", saldo);
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
    }
}