#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista duplamente ligada
typedef struct Node {
    int data;               // Armazena o dado (valor inteiro)
    struct Node* next;      // Ponteiro para o próximo nó
    struct Node* prev;      // Ponteiro para o nó anterior
} Node;

Node* head = NULL;  // Ponteiro global para o primeiro nó da lista

// Função para inserir um novo nó no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    newNode->data = value;  // Define o valor do novo nó
    newNode->next = head;   // Aponta o próximo do novo nó para o antigo primeiro nó
    newNode->prev = NULL;   // O anterior do novo nó é NULL, pois ele será o primeiro nó

    // Se a lista não está vazia, atualiza o ponteiro prev do antigo primeiro nó
    if (head != NULL)
        head->prev = newNode;
    
    head = newNode;  // Atualiza o ponteiro head para o novo nó
}

// Função para deletar um nó específico da lista
void deleteNode(Node* node) {
    if (node == head)  // Se o nó a ser deletado é o primeiro nó, atualiza o head
        head = node->next;
    
    if (node->next != NULL)  // Atualiza o ponteiro prev do próximo nó, se existir
        node->next->prev = node->prev;
    
    if (node->prev != NULL)  // Atualiza o ponteiro next do nó anterior, se existir
        node->prev->next = node->next;
    
    free(node);  // Libera a memória alocada para o nó
}

// Função para imprimir todos os elementos da lista
void printList() {
    Node* temp = head;  // Começa do primeiro nó
    while (temp != NULL) {  // Percorre a lista até o final
        printf("%d ", temp->data);  // Imprime o valor do nó atual
        temp = temp->next;  // Avança para o próximo nó
    }
    printf("\n");  // Quebra de linha após imprimir a lista
}

// Função para buscar um valor específico na lista e mostrar seus vizinhos
void searchAndPrintNeighbors(int value) {
    Node* temp = head;  // Começa do primeiro nó
    while (temp != NULL) {  // Percorre a lista
        if (temp->data == value) {  // Se o valor é encontrado
            printf("Valor %d encontrado.\n", value);
            
            // Exibe o valor do nó anterior, se existir
            if (temp->prev != NULL)
                printf("Anterior: %d\n", temp->prev->data);
            else
                printf("Anterior: NULL\n");

            // Exibe o valor do nó próximo, se existir
            if (temp->next != NULL)
                printf("Próximo: %d\n", temp->next->data);
            else
                printf("Próximo: NULL\n");

            return;  // Sai da função após encontrar o valor
        }
        temp = temp->next;  // Avança para o próximo nó
    }
    printf("Valor %d não encontrado na lista.\n", value);  // Valor não encontrado
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
                insertFront(valor);
                break;
            case 2:
                printf("Digite o valor do nó a ser deletado: ");
                scanf("%d", &valor);
                Node* temp = head;
                while (temp != NULL && temp->data != valor) {
                    temp = temp->next;
                }
                if (temp != NULL) {
                    deleteNode(temp);
                    printf("Nó com valor %d deletado.\n", valor);
                } else {
                    printf("Valor %d não encontrado na lista.\n", valor);
                }
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                searchAndPrintNeighbors(valor);
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
