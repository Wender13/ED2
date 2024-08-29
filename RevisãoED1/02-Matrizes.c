/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, m, soma = 0;
    
    scanf("%d", &m);
    
    int **matriz = malloc(m * sizeof(int*));
    
    for (i = 0; i < m; i++) 
    {
        matriz[i] = malloc (m * sizeof (int));
    }

    printf("Insira os elementos da matriz 3x3:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
