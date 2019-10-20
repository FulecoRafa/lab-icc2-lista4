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

void print_comb(int *array , int *out , int k){
    for(int i = 0 ; i < k ; i++){
        printf("%d " , array[out[i]]);
    }
    printf("\n");
}

int somas_recursivas(int *array , int i , int soma , int index , int *out , int many , int n , int k){
    int soma = 0;
    if(soma == 0 && many == n){
        print_comb(array , out , k);
        return (1);
    }else if(soma < 0){
        return (0);
    }else{
        for(int j = i ; j < k ; j++){
            out[index] = j;
            soma += somas_recursivas(array , j+1 , soma-array[j] , index+1 , out , many + 1 , n , k);
        }
        return (soma);
    }
}

int main(void){
    int k , n;
    int* array;
    srand(time(NULL));
    printf("Quantos números? ");
    scanf("%d" , &k);
    printf("Tamanho da upla: ");
    scanf("%d" , &n);
    array = (int*) malloc(sizeof(int) * k);
    for(int i = 0 ; i < k ; i++){
        array[i] = rand() % 1090;
    }
    quick_sort(array , 0 , k-1);
    int output[n];


    return 0;
}