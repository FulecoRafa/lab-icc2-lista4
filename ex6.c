#include <stdio.h>

#define N 16

void troca(int* a, int* b) {
	int aux = *a;
	
	*a = *b;
	*b = aux;
}

void heapify(int* v, int n) {
	int pai; int filho;
	for (int i = 1; i < n; i++) {
		filho = i;
		pai = (filho - 1)/2;
		
		while (pai >= 0 && v[filho] > v[pai]) {
			troca(v + pai, v + filho);
			filho = pai;
			pai = (pai - 1)/2;
		}
	}
}

int heapsort(int* v, int n) {
	heapify(v, n);
	int fim = n - 1;

	int pai;
	int filho;

	for (int i = 1; i < fim; i++) {
		filho = i;
		while (pai >= 0 && v[filho] < v[pai]) {
			
		}
	}
}

int main(int argc, char const *argv[]) {
	int v[N] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};

	heapsort(v, N);
	for (int i = 0; i < N; i++) printf("%d ", v[i]);
	printf("\n");

	return 0;
}