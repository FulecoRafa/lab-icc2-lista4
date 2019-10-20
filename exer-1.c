#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

void merge(int* p, int ini, int meio, int fim){
    int i, j, k;
    int n1 = meio - ini + 1;
    int n2 =  fim - meio;
 
    int* I = (int*) malloc(sizeof(int)*n1); //vetor auxiliar da esquerda
    int* F = (int*) malloc(sizeof(int)*n2); //vetor auxiliar da direita
 
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
        if (I[i] <= F[j]){
            p[k] = I[i];
            i++;
        }
        else{
            p[k] = F[j];
            j++;
        }
        k++;
    }
 
    while (i < n1){ //atribui os elementos que faltaram do vetor da esquerda
        p[k] = I[i];
        i++;
        k++;
    }
 
    while (j < n2){ //atribui os elementos que faltaram do vetor da direita
        p[k] = F[j];
        j++;
        k++;
    }
}

void mergesort(int* p, int ini, int fim)
{
    if (ini < fim) //quando inicio = fim o vetor tem apenas um elemento, desta forma atingindo a condiçãode parada
    {
        int meio = (ini+fim)/2; //encontra a metade de cada recursão
 
        mergesort(p, ini, meio); //metade da esquerda
        mergesort(p, meio+1, fim); //metade da direita
 
        merge(p, ini, meio, fim);
    }
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int convertFromType(char type){
    if(type == 'a') return 0;
    else if(type == 'b') return 1;
    else if(type == 'c') return 2;
    else return 3;
}

char convertToType(int type){
    if(type == 0) return 'A';
    else if(type == 1) return 'B';
    else if(type == 2) return 'C';
    else return 'D';
}

int main(void){
    char type;
    int MAX;
    int merge = 0;
    printf("Merge ou Quick?[M/q] ");
    scanf(" %c" , &type);
    type = tolower(type);
    if(type == 'm') merge++;
    type = 1;
    printf("Número de varinhas: ");
    scanf("%d" , &MAX);
    int *array;
    array = (int*) malloc(sizeof(int) * MAX);
    for(int i = 0 ; i < MAX ; i++){
        printf("Tipo de varinha [A/B/C/D]: ");
        scanf(" %c" , &type);
        type = tolower(type);
        if(type != 'a' && type != 'b' && type != 'c' && type != 'd'){
            printf("[!]Tipo inválido!\n");
            i--;
        }else array[i] = convertFromType(type);
    }
    // printf("+----------+\n");
    // int k = 0;
    // for( ; k < MAX ;){
    //     printf("| %d |\n" , array[k]);
    //     k++;
    // }
    // printf("+----------+\n");
    if(merge == 1){
        mergesort(array , 0 , MAX - 1);
    }else{
        quick_sort(array , 0 , MAX - 1);
    }
    // printf("+----------+\n");
    // k = 0;
    // for( ; k < MAX ;){
    //     printf("| %d |\n" , array[k]);
    //     k++;
    // }
    // printf("+----------+\n");

    for(int i = 0 ; i < MAX ; i++){
        printf(" %c\n" , convertToType(array[i]));
    }
}