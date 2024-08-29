#include <stdio.h>

int main() {
	int i , tam;

	scanf("%d", &tam);
	int vetor[tam];

	for (i = 0; i < tam; i++) {
		scanf("%d", &vetor[i]);
	}

	printf("Vetor invertido:\n");
	for (i = tam; i > 0; i--) {
		printf("%d ", vetor[i-1]);
	}

	return 0;
}
