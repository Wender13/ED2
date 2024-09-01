#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            printf("Elemento %d encontrado na posição %d\n", elemento, i);
            return;
        }
    }
    printf("Elemento %d não encontrado\n", elemento);
}

void inverter() {
    for (int i = 0; i < tamanho / 2; i++) {
        int temp = lista[i];
        lista[i] = lista[tamanho - i - 1];
        lista[tamanho - i - 1] = temp;
    }
}

int encontrar_maximo() {
    if (tamanho == 0) {
        printf("A lista está vazia!\n");
        return -1; 
    }
    int maximo = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] > maximo) {
            maximo = lista[i];
        }
    }
    return maximo;
}

int encontrar_minimo() {
    if (tamanho == 0) {
        printf("A lista está vazia!\n");
        return -1;
    }
    int minimo = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] < minimo) {
            minimo = lista[i];
        }
    }
    return minimo;
}

void ordenar() {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    imprimir();

    remover(1);
    imprimir();

    inserir(40);
    inserir(50);
    imprimir();

    buscar(30);

    inverter();
    printf("Lista invertida: \n");
    imprimir();

    printf("Máximo: %d\n", encontrar_maximo());
    printf("Mínimo: %d\n", encontrar_minimo());

    ordenar();
    printf("Lista ordenada: \n");
    imprimir();

    return 0;
}
