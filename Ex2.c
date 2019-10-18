#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

//Definição do tamanho do vetor
#define TMAX 15

//Struct que guarda as informações da maça
struct macas
{
    int tamanho;
    char cor;
};
typedef struct macas maca;

//funções do quicksort para ordenar cor e tamanho em maça
void quick_sort_macacor(maca* a , int esquerda , int direita);

void quick_sort_macatamanho(maca* a , int esquerda , int direita);

//funções do Mergesort para ordenar cor e tamanho em maça

//Sempre um par para recursão
void merge_macacor(maca* p, int ini, int meio, int fim);

void mergesort_macacor(maca* p, int ini, int fim);

void merge_macatamanho(maca* p, int ini, int meio, int fim);

void mergesort_macatamanho(maca* p, int ini, int fim);

//função para imprimir um vetor de tamanho TMAX.
void imprimevet(maca* V);

void merge_macacor(maca* p, int ini, int meio, int fim){
    int i, j, k;
    int n1 = meio - ini + 1;
    int n2 =  fim - meio;
 
    maca* I = (maca*) malloc(sizeof(maca)*n1); //vetor auxiliar da esquerda
    maca* F = (maca*) malloc(sizeof(maca)*n2); //vetor auxiliar da direita
 
    for (i = 0; i < n1; i++){ //atribui os valores aos vetores
        I[i] = p[ini + i];
    }
    for (j = 0; j < n2; j++){
        F[j] = p[meio + 1+ j];
    }
 
    i = 0;
    j = 0;
    k = ini;
    while (i < n1 && j < n2){ //compara qual dos dois é maior e atribui ao vetor que os originou em ordem
        if ((int) I[i].cor <= (int) F[j].cor){
            p[k].cor = I[i].cor;
            i++;
        }
        else{
            p[k].cor = F[j].cor;
            j++;
        }
        k++;
    }
 
    while (i < n1){ //atribui os elementos que faltaram do vetor da esquerda
        p[k].cor = I[i].cor;
        i++;
        k++;
    }
 
    while (j < n2){ //atribui os elementos que faltaram do vetor da direita
        p[k].cor = F[j].cor;
        j++;
        k++;
    }
}

void merge_macatamanho(maca* p, int ini, int meio, int fim){
    int i, j, k;
    int n1 = meio - ini + 1;
    int n2 =  fim - meio;
 
    maca* I = (maca*) malloc(sizeof(maca)*n1); //vetor auxiliar da esquerda
    maca* F = (maca*) malloc(sizeof(maca)*n2); //vetor auxiliar da direita
 
    for (i = 0; i < n1; i++){ //atribui os valores aos vetores
        I[i] = p[ini + i];
    }
    for (j = 0; j < n2; j++){
        F[j] = p[meio + 1+ j];
    }
 
    i = 0;
    j = 0;
    k = ini;
    while (i < n1 && j < n2){ //compara qual dos dois é maior e atribui ao vetor que os originou em ordem
        if ( I[i].tamanho <= F[j].tamanho){
            p[k].tamanho = I[i].tamanho;
            i++;
        }
        else{
            p[k].tamanho = F[j].tamanho;
            j++;
        }
        k++;
    }
 
    while (i < n1){ //atribui os elementos que faltaram do vetor da esquerda
        p[k].tamanho = I[i].tamanho;
        i++;
        k++;
    }
 
    while (j < n2){ //atribui os elementos que faltaram do vetor da direita
        p[k].tamanho = F[j].tamanho;
        j++;
        k++;
    }
}

void mergesort_macacor(maca* p, int ini, int fim)
{
    if (ini < fim) //quando inicio = fim o vetor tem apenas um elemento, desta forma atingindo a condiçãode parada
    {
        int meio = (ini+fim)/2; //encontra a metade de cada recursão
 
        mergesort_macacor(p, ini, meio); //metade da esquerda
        mergesort_macacor(p, meio+1, fim); //metade da direita
 
        merge_macacor(p, ini, meio, fim);
    }
}

void mergesort_macatamanho(maca* p, int ini, int fim)
{
    if (ini < fim) //quando inicio = fim o vetor tem apenas um elemento, desta forma atingindo a condiçãode parada
    {
        int meio = (ini+fim)/2; //encontra a metade de cada recursão
 
        mergesort_macatamanho(p, ini, meio); //metade da esquerda
        mergesort_macatamanho(p, meio+1, fim); //metade da direita
 
        merge_macatamanho(p, ini, meio, fim);
    }
}

void quick_sort_macatamanho(maca* a , int esquerda , int direita){
    int i, j;
    int pivotamanho,auxiliar;
     
    i = esquerda;
    j = direita;
    pivotamanho = a[(esquerda + direita) / 2].tamanho;
     
    while(i <= j) {
        while(a[i].tamanho < pivotamanho && i < direita) {
            i++;
        }
        while(a[j].tamanho > pivotamanho && j > esquerda) {
            j--;
        }
        if(i <= j) {
            auxiliar = a[i].tamanho;
            a[i].tamanho = a[j].tamanho;
            a[j].tamanho = auxiliar;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort_macatamanho(a, esquerda, j);
    }
    if(i < direita) {
        quick_sort_macatamanho(a, i, direita);
    }
}

void quick_sort_macacor(maca *a, int esquerda, int direita) {
    int i, j;
    char pivocor,auxiliar;
     
    i = esquerda;
    j = direita;
    pivocor = a[(esquerda + direita) / 2].cor;
     
    while(i <= j) {
        while((int)a[i].cor < (int)pivocor && i < direita) {
            i++;
        }
        while((int)a[j].cor > (int)pivocor && j > esquerda) {
            j--;
        }
        if(i <= j) {
            auxiliar = a[i].cor;
            a[i].cor = a[j].cor;
            a[j].cor = auxiliar;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort_macacor(a, esquerda, j);
    }
    if(i < direita) {
        quick_sort_macacor(a, i, direita);
    }
}


void ordena_macas(maca* V,int N){
    int i,inicio=0,merge = 0;
    char coratual='A',type;

    //Pergunta para selecionar se deve-se utilizar o Quicksort ou o Mergesort
    printf("Merge ou Quick?[M/q] ");
    scanf(" %c" , &type);
    type = tolower(type);
    if(type == 'm') merge++;

    //Instruções para ordenar via merge
    if(merge==1){
        mergesort_macacor(V,0,N-1); // atenção ao indice final do vetor (quando i muda, já é outra letra)
        for(i=0;i<N;i++){
        if(V[i].cor!=coratual){
            coratual=V[i].cor;
            mergesort_macatamanho(V,inicio,i-1);
            inicio=i;
        }
        else if (i=N-1){
            mergesort_macatamanho(V,inicio,i);
        }
    }
        }
    //Instruções para ordenar via quick
    else{
    quick_sort_macacor(V,0,N-1);
    for(i=0;i<N;i++){
        
        if(V[i].cor!=coratual){
            coratual=V[i].cor;
            quick_sort_macatamanho(V,inicio,i-1);
            inicio=i;
        }
        else if(i=N-1){
            quick_sort_macatamanho(V,inicio,i);
        }
    }
    }
}

void imprimevet(maca* V){
    int i;
    for(i=0;i<TMAX;i++){
        printf("[%d, %c] ",V[i].tamanho,V[i].cor);
    }
    printf("\n");
}

int main (void){

//cria o vetor e variáveis auxiliares
maca* V=NULL;
int seed,i;

V=(maca*)malloc(sizeof(maca)*TMAX);
if(V==NULL){printf("Deu erro aqui ó"); exit(1);}

//gera uma semente para geração de um vetor aleatório
srand(time(NULL));

//Preenchimento do vetor com valores aleatórios
for(i=0;i<TMAX;i++){
    V[i].tamanho=(rand()%4) +1;;
    V[i].cor=(rand()%4 + 65);
}

imprimevet(V);

// Chama a função de ordenação de maçãs
ordena_macas(V,TMAX);

imprimevet(V);

    return 0;
}
