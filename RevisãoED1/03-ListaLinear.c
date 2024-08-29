/*
O código abaixo apresenta a implementação de uma lista linear.

Para esse exemplo, faça:
- Implemente funções adicionais como buscar(int elemento) para encontrar a posição de um elemento na lista.
ou 
- Adicione métodos para inverter a lista, encontrar o máximo/mínimo, ou ordenar a lista.
*/

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

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void encontrarMax()
{
  int max = lista[0];
  for(int i = 0; i < tamanho; i++)
  {
    if(lista[i] > max) max = lista[i];
  }
  printf("Maior elemento da lista\n");
  printf("%d\n", max);
}

void encontrarMin()
{
  int min = lista[0];
  for(int i = 0; i < tamanho; i++)
  {
    if(lista[i] < min) min = lista[i];
  }
  printf("Maior elemento da lista\n");
  printf("%d\n", min);
}

void inverter()
{
  int temp[tamanho], tam = 0;
  for(int i = tamanho; i > 0; i--)
  {
    temp[tam] = lista[i];
    tam++;
  }
  for(int i = 0; i < tamanho; i++)
  {
    lista[i] = temp[i];
  }
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    imprimir();
    remover(1);
    imprimir();
    encontrarMax();
    encontrarMin();
    inverter();
    imprimir();
    
    return 0;
}

https://onecompiler.com/c/
