// Caroline Jenuario
// Alexandre Cabral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct no
{
    int resultado;          // resultado da conta
    struct no *no_anterior; // aponta pro no de baixo
} No;

No *push(No *pilha, int num)
{
    No *novo_no = malloc(sizeof(No)); // alocar espaço para o novo no
    if (novo_no)
    {
        novo_no->resultado = num;
        novo_no->no_anterior = pilha;
        return novo_no;
    }
    else
        printf("Erro na alocação de memoria.\n");
    return NULL;
}

No *pop(No **pilha)
{
    No *remover = NULL;
    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->no_anterior;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void imprimir(No *pilha)
{
    printf("\nNumeros de 1 a 1.000.000 em PILHA:\n");
    while (pilha)
    {
        printf("%d\n", pilha->resultado);
        pilha = pilha->no_anterior;
    }
}

int somar_numeros(int num)
{
    No *remover, *pilha = NULL;
    while (num > 1)
    {
        pilha = push(pilha, num);
        num--;
    }
    imprimir(pilha);
    while (pilha)
    {
        remover = pop(&pilha);
        num = num + remover->resultado;
        free(remover);
    }
    return num;
}

int somar_numeros_zeros(int num)
{
    No *remover, *pilha = NULL;
    while (num > 1)
    {
        pilha = push(pilha, num == 0);
        num--;
    }
    imprimir(pilha);
    while (pilha)
    {
        remover = pop(&pilha);
        num = num + remover->resultado;
        free(remover);
    }
    return num = 0;
}

// funcoes para a fila

No *inserir_fila(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->resultado = num;
        novo->no_anterior = NULL;
        if (*fila == NULL)
            *fila = novo;
        else
        {
            aux = *fila;
            while (aux->no_anterior)
                aux = aux->no_anterior;
            aux->no_anterior = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
    return *fila;
}

No *remover_da_fila(No **fila)
{
    No *remover = NULL;
    if (*fila)
    {
        remover = *fila;
        *fila = remover->no_anterior;
    }
    else
        printf("A fila está vazia.\n");
    return remover;
}

void imprimir_fila(No *fila)
{
    printf("\nNumero de 1 a 1.000.000 em FILA: \n");
    while (fila)
    {
        printf("%d\n", fila->resultado);
        fila = fila->no_anterior;
    }
}

int somar_numeros_fila(int num)
{
    No *remover, *fila = NULL;
    while (num > 0)
    {
        fila = inserir_fila(&fila, num);
        num--;
    }
    imprimir_fila(fila);
    while (fila)
    {
        remover = remover_da_fila(&fila);
        num = num + remover->resultado;
        free(remover);
    }
    return num;
}

int somar_numeros_zero_fila(int num)
{
    No *remover, *fila = NULL;
    while (num > 1)
    {
        fila = inserir_fila(&fila, num == 0);
        num--;
    }
    imprimir_fila(fila);
    while (fila)
    {
        remover = remover_da_fila(&fila);
        num = num + remover->resultado;
        free(remover);
    }
    return num = 0;
}

int main()
{
    int op;
    clock_t t;
    int resultado = 100000;
    do
    {
        printf("\nDigite a opcao desejada: \n1- Soma de 1 a 1.000.00 em pilha. \n2- Alterar todos os numeros da pilha para zero. \n3- Soma de 1 a 1.000.000 em fila. \n4- Alterar todos os numeros da fila para zero. \n0- Sair. \n ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            t = clock();
            printf("Soma da PILHA: %d\n", somar_numeros(resultado));
            t = clock() - t;
            printf("Tempo de execucao: %lf \n",
                   ((double)t) / ((CLOCKS_PER_SEC / 1000)));
            break;
        case 2:
            t = clock();
            printf("Soma: %d\n", somar_numeros_zeros(resultado));
            t = clock() - t;
            printf("Tempo de execucao: %lf  \n",
                   ((double)t) / ((CLOCKS_PER_SEC / 1000)));
            break;
        case 3:
            t = clock();
            printf("Soma da FILA: %d\n", somar_numeros_fila(resultado));
            t = clock() - t;
            printf("Tempo de execucao: %lf \n",
                   ((double)t) / ((CLOCKS_PER_SEC / 1000)));
            break;
        case 4:
            t = clock();
            printf("\nSoma da FILA: %d\n",
                   somar_numeros_zero_fila(resultado));
            printf("Tempo de execucao: %lf \n",
                   ((double)t) / ((CLOCKS_PER_SEC / 1000)));
            break;
        }
    } while (op != 0);
}
