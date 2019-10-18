#include <stdio.h>
#include "apple.h"

int main(int argc, char const *argv[]) {
	Apple a[N];
	Apple aux;
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &(aux.tamanho), &(aux.cor));
		a[i] = aux;
	}

	int pos = maximo(a, 0, n - 1);
	printf("%d %c\n", a[pos].tamanho, a[pos].cor);

	return 0;
}