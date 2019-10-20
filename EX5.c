#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//Imprime uma combinação válida
void print_comb(int *array , int *out , int index){
    printf("[Combinação] -> ");
    for(int i = 0 ; i < index ; i++){
        printf("%d " , array[out[i]]);
    }
    printf("\n");
}

//Faz as somas de n valores do vetor, imprime quais somas são iguais à SOMA e retorna a quantidade de combinações
//Array é a array de valores, i o índice tratado na array , soma a soma que queremos atingir, out um vetor de índices das respostas, index o índice de out, many
//quantos valores foram encontrados até agora, n o tamanho da upla e k o tamanho de array
int somas_recursivas(int *array , int i , int soma , int index , int *out , int many , int n , int k){
    int total = 0;
    if(soma == 0 && many == n){//caso base para uma combinação válida
        print_comb(array , out , index);
        return (1);
    }else if(soma < 0 || many > n){//impede que o procedimento continue, pois a soma já ultrapassou SOMA
        return (0);
    }else{
        for(int j = i ; j < k ; j++){//Chama para cada valor do vetor seguinte ao valor atual
            out[index] = j;
            //faz a chamada recursiva deste função
            //Ele reduz da soma o valor adicionado agora como resposta, aumenta um em i, em many e em index
            total += somas_recursivas(array , j+1 , soma-array[j] , index+1 , out , many + 1 , n , k);
        }
        return (total);
    }
}

int main(void){
    int k , n , soma;
    int* array;
    srand(time(NULL));
    printf("Quantos números? ");
    scanf("%d" , &k);
    printf("Tamanho da upla: ");
    scanf("%d" , &n);
    printf("Soma: ");
    scanf("%d" , &soma);
    array = (int*) malloc(sizeof(int) * k);
    printf("[Sequência] -> ");
    for(int i = 0 ; i < k ; i++){
        array[i] = rand() % 1090;
        //array[i] = i;  //Descomente essa linha e comente essa para poder ter uma seuência já ordenada e mais fácil de ler
        printf("%d " , array[i]);
    }
    printf("\n");
    quick_sort(array , 0 , k-1);
    printf("[Sequência ordenada] -> ");
    for(int i = 0 ; i < k ; i++){
        printf("%d " , array[i]);
    }
    printf("\n\n");
    int output[n];
    int total = somas_recursivas(array , 0 , soma , 0 , output , 0 , n , k);
    if(total == 0){
        printf("Mal feito feito!\n");
    }else{
        printf("Foram encontradas %d combinações\n" , total);
    }

    return 0;
}