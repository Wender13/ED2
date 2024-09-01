#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
} No;

No* cabeca = NULL;

void inserirInicio(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = cabeca;
    novoNo->anterior = NULL;

    if (cabeca != NULL)
        cabeca->anterior = novoNo;

    cabeca = novoNo;
}

void deletarNo(No* no) {
    if (no == cabeca)
        cabeca = no->proximo;
    
    if (no->proximo != NULL)
        no->proximo->anterior = no->anterior;
    
    if (no->anterior != NULL)
        no->anterior->proximo = no->proximo;

    free(no);
}

void imprimirLista() {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

void buscarEImprimirVizinhos(int valor) {
    No* temp = cabeca;
    while (temp != NULL) {
        if (temp->dado == valor) {
            printf("Valor %d encontrado.\n", valor);
            
            if (temp->anterior != NULL)
                printf("Anterior: %d\n", temp->anterior->dado);
            else
                printf("Anterior: NULL\n");

            if (temp->proximo != NULL)
                printf("Próximo: %d\n", temp->proximo->dado);
            else
                printf("Próximo: NULL\n");

            return;
        }
        temp = temp->proximo;
    }
    printf("Valor %d não encontrado na lista.\n", valor);
}

int main() {
    int escolha, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir valor\n");
        printf("2. Deletar nó\n");
        printf("3. Imprimir lista\n");
        printf("4. Buscar valor e mostrar vizinhos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                inserirInicio(valor);
                break;
            case 2:
                printf("Digite o valor do nó a ser deletado: ");
                scanf("%d", &valor);
                No* temp = cabeca;
                while (temp != NULL && temp->dado != valor) {
                    temp = temp->proximo;
                }
                if (temp != NULL) {
                    deletarNo(temp);
                    printf("Nó com valor %d deletado.\n", valor);
                } else {
                    printf("Valor %d não encontrado na lista.\n", valor);
                }
                break;
            case 3:
                imprimirLista();
                break;
            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscarEImprimirVizinhos(valor);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 5);

    return 0;
}