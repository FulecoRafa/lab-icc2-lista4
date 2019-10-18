#include <stdio.h>

#define N 1000000

#define TRUE 1
#define FALSE 0

#define VERMELHO	'A'
#define VERDE 		'B'
#define AMARELO		'C'
#define AZUL 		'D'

typedef int boolean;

typedef char tipoCor;

//A função less retorna TRUE se a maça "b" for tão ou mais saborosa que a maçã b
boolean less(Apple a, Apple b) {
	return a.cor > b.cor || (a.cor == b.cor && a.tamanho < b.tamanho); 
}	

//A função maximo utiliza o método de divisão e conquista para retornar a posição do maior elemento
//O caso base da recursão ocorre quando há apenas um elemento no vetor
//Quando o caso não acontece, a função maximo() é chamada recursivamente no subvetor da esquerda
//e da direita. Então, é retornada a posição do maior elemento (a maior e mais saborosa)
int maximo(Apple a[], int inicio, int fim) {
	if (inicio == fim) return inicio;
	int meio = (inicio + fim)/2;

	int maxEsq = maximo(a, inicio, meio);
	int maxDir = maximo(a, meio + 1, fim);

	return less(a[maxEsq],a[maxDir]) ? maxDir : maxEsq;
}

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