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

void print_comb(int *array , int *out , int index){
    printf("[Combinação] -> ");
    for(int i = 0 ; i < index ; i++){
        printf("%d " , array[out[i]]);
    }
    printf("\n");
}

int somas_recursivas(int *array , int i , int soma , int index , int *out , int many , int n , int k){
    int total = 0;
    if(soma == 0 && many == n){
        print_comb(array , out , index);
        return (1);
    }else if(soma < 0 || many > n){
        return (0);
    }else{
        for(int j = i ; j < k ; j++){
            out[index] = j;
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