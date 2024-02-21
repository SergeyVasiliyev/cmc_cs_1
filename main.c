#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int COMPARES = 0;
int SWAPS = 0;

void arr1(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }
}

void arr2(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = n - i;
    }
}

void arr3(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = rand();
    }
}

int main(void){
    int n = 1000;
    int *a;
    a = (int*)malloc(n * sizeof(int));
    arr3(a, n);
    sort(a, n);
    printf("%d %d", COMPARES, SWAPS);
    free(a);
    return 0;
}
