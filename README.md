# Sistema ATM — Caixa Eletrônico em C

Projeto desenvolvido para a disciplina **Data Structures and Algorithms** da FIAP.  
Implementação de um caixa eletrônico em linguagem C

---

## Integrantes

| # | Nome | RM |
|---|------|--------|
| 1 | Gabriel | 570589 |
| 2 | Fernando | 571408 |
| 3 | Leo | 569556 |
| 4 | Thor | 569543 |

---

## Estrutura dos Commits

### Commit 1 — Gabriel
**`includes, constantes, prototipos e main`**

Criação da estrutura base do programa:
- `#include <stdio.h>` e `#include <string.h>`
- Constantes `#define MAX_OPERACOES 3` e `#define TAM_TIPO 20`
- Protótipos de todas as funções
- Função `main()` com declaração e inicialização dos vetores, loop `do-while` e `switch` despachante

---

### Commit 2 — Léo
**`exibirMenu, consultarSaldo, pausar e limparBuffer`**

Funções de interface e utilitários:
- `exibirMenu()` — imprime as opções do caixa eletrônico
- `consultarSaldo(float saldo)` — exibe o saldo formatado; demonstra passagem por valor (cópia local, original inalterado)
- `pausar()` — aguarda o usuário pressionar Enter
- `limparBuffer()` — descarta caracteres residuais do `stdin` para evitar leituras incorretas

---

### Commit 3 — Thor
**`realizarDeposito e realizarSaque com validacoes`**

Funções de operações financeiras:
- `realizarDeposito()` — lê e valida o valor; retorna `float` com o novo saldo via `return`
- `realizarSaque()` — aplica três validações encadeadas: valor positivo, limite de R$ 1.000,00 e saldo suficiente; retorna `float` com o novo saldo
- Ambas recebem `char tipos[][TAM_TIPO]` e `float valores[]` como parâmetros para registrar a operação

---

### Commit 4 — Fernando
**`registrarOperacao e exibirExtrato`**

Funções de histórico e exibição:
- `registrarOperacao()` — insere a operação no vetor; quando cheio, usa laço `for` para deslocar os elementos com `strcpy` e descarta o mais antigo (histórico circular de até 3 operações)
- `exibirExtrato()` — percorre os vetores com `for` de `0` até `totalOperacoes-1`, imprimindo cada string com `%s`

---

## Como compilar e executar

```bash
# Compilar
gcc main.c -o atm

# Executar
./atm
```

---

## Funcionalidades

- [x] Consultar saldo
- [x] Realizar saque com limite e validação de saldo
- [x] Realizar depósito
- [x] Consultar extrato (últimas 3 operações)
- [x] Tratamento de opções inválidas
- [x] Histórico circular de operações
