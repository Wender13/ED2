#include <stdio.h>
#include <stdlib.h>

int* pilha;
int tamanhoMaximo = 3;
int topo = -1;

void empilhar(int elemento) {
    if (topo < tamanhoMaximo - 1) {
        pilha[++topo] = elemento;
    } else {
        expandirPilha();
        pilha[++topo] = elemento;
    }
}

int desempilhar() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--];
    }
}

int elementoTopo() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];
    }
}

void imprimirPilha() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int estaVazia() {
    return topo == -1;
}

void expandirPilha() {
    int novoTamanho = tamanhoMaximo * 2;
    int* novaPilha = (int*)malloc(novoTamanho * sizeof(int));

    if (novaPilha == NULL) {
        printf("Erro ao alocar memória para expansão da pilha.\n");
        return;
    }

    for (int i = 0; i <= topo; i++) {
        novaPilha[i] = pilha[i];
    }

    free(pilha);
    pilha = novaPilha;
    tamanhoMaximo = novoTamanho;

    printf("Pilha expandida para o novo tamanho de %d.\n", tamanhoMaximo);
}

int main() {
    pilha = (int*)malloc(tamanhoMaximo * sizeof(int));

    empilhar(10);
    empilhar(20);
    empilhar(30);
    imprimirPilha();
    printf("Elemento no topo: %d\n", elementoTopo());
    printf("Elemento removido: %d\n", desempilhar());
    imprimirPilha();

    empilhar(40);
    empilhar(50);
    empilhar(60);
    imprimirPilha();

    free(pilha);
    return 0;
}