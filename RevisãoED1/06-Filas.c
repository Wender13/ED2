#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Fila {
    No* frente;
    No* tras;
} Fila;

Fila* criarFila() {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->frente = q->tras = NULL;
    return q;
}

void enfileirar(Fila* q, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    if (q->tras == NULL) { 
        q->frente = q->tras = novoNo;
    } else { 
        q->tras->proximo = novoNo;
        q->tras = novoNo;
    }
}

int desenfileirar(Fila* q) {
    if (q->frente == NULL) { 
        printf("Fila está vazia.\n");
        return -1;
    }
    No* temp = q->frente;
    int dado = temp->dado;
    q->frente = q->frente->proximo;
    if (q->frente == NULL) {
        q->tras = NULL;
    }
    free(temp);
    return dado;
}

int estaVazia(Fila* q) {
    return q->frente == NULL;
}

void imprimirFila(Fila* q) {
    if (estaVazia(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    No* temp = q->frente;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

int contarElementos(Fila* q) {
    int contagem = 0;
    No* temp = q->frente;
    while (temp != NULL) {
        contagem++;
        temp = temp->proximo;
    }
    return contagem;
}

void limparFila(Fila* q) {
    No* temp = q->frente;
    while (temp != NULL) {
        No* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    q->frente = q->tras = NULL;
    printf("A fila foi limpa.\n");
}

int main() {
    Fila* q = criarFila();
    enfileirar(q, 10);
    enfileirar(q, 20);
    enfileirar(q, 30);
    imprimirFila(q);
    
    printf("Número de elementos na fila: %d\n", contarElementos(q));

    printf("Desenfileirado: %d\n", desenfileirar(q));
    imprimirFila(q);
    printf("Desenfileirado: %d\n", desenfileirar(q));
    imprimirFila(q);
    printf("Desenfileirado: %d\n", desenfileirar(q));
    imprimirFila(q);

    printf("Número de elementos na fila: %d\n", contarElementos(q));

    limparFila(q);
    imprimirFila(q);

    free(q);
    return 0;
}
