#include <stdio.h>

#define N 16
#define MAX(a,b) a > b ? a : b


void troca(int* a, int* b) {
	int aux = *a;
	
	*a = *b;
	*b = aux;
}

void heapify(int* v, int n) {
	int pai; int filho;
	for (int i = 0; i < n; i++) {
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

	int fimHeap = fim;
	int pai;
	int filho;

	for (int i = 0; i < fim; i++) {
		troca(v, v + fim - i);
		pai = 0;
		filho = 1;
		fimHeap--;
		while (filho <= fimHeap) {
			if (filho < fimHeap && v[filho + 1] > v[filho]) filho++;
			if (v[filho] > v[pai]) {
				troca(v + pai, v + filho);
				pai = filho;
				filho = 2*pai + 1;
			}
			else {
				break;
			}
		}
	}
}

void merge(int* v, int inicio, int meio, int fim) {
	int n = fim - inicio + 1;
	int vAux[n];
	int aux = 0;

	int inicio1 = inicio;
	int inicio2 = meio + 1;

	while (inicio1 <= meio && inicio2 <= fim) {
		if (v[inicio1] < v[inicio2]) {
			vAux[aux] = v[inicio1];
			inicio1++;
		}
		else {
			vAux[aux] = v[inicio2];
			inicio2++;
		}
		aux++;
	}
	while (inicio1 <= meio) {
		vAux[aux] = v[inicio1];
		inicio1++;
		aux++;
	}
	while (inicio2 <= fim) {
		vAux[aux] = v[inicio2];
		inicio2++;
		aux++;
	}
	for (int i = 0; i < n; i++) v[inicio + i] = vAux[i];
}

void mergesort(int* v, int inicio, int fim) {

	if(inicio < fim) {
		int meio = (inicio + fim)/2;

		mergesort(v, inicio, meio);
		mergesort(v, meio + 1, fim);
		merge(v, inicio, meio, fim);
	}
}

void partition(int* v, int inicio, int fim, int* i, int* j) {
	int pivo = v[(inicio + fim)/ 2];

	int esq = inicio;
	int dir = fim;

	for (int i = 0; i < fim - inicio + 1; i++) printf("%d ", v[i]);
	printf("    "); 
	do {
		while (v[esq] < pivo) esq++;
		while (v[dir] > pivo) dir--;
		if (esq <= dir) {
			troca(v + esq, v + dir);
			esq++;
			dir--;
		}
	} while (esq < dir);
	*i = esq;
	*j = dir;
}

int quicksort(int* v, int inicio, int fim) {
		int i, j;
		partition(v, inicio, fim, &i, &j);
		printf("\n");
		if (inicio < j) quicksort(v, inicio, j);
		if (i < fim) quicksort(v, i, fim);
}


int main(int argc, char const *argv[]) {
	int v[N] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
	
	switch (argc) {
		case 2:
			if (argv[1][0] == 'h') {
				heapsort(v, N);
				break;
			}
			else if (argv[1][0] == 'm') {
				mergesort(v, 0, N - 1);
				break;
			}
			else if (argv[1][0] == 'q') {
				quicksort(v, 0, N - 1);
				break;
			}
		default:
			printf("Use 'h', 'q' ou 'm' como argumento para heapsort, quicksort ou mergesort, respectivamente\n");
			printf("Exemplo:\n");
			printf("ex6 h\n\n");
			break;
	}
	for (int i = 0; i < N; i++) printf("%d ", v[i]);
	printf("\n");

	return 0;
}