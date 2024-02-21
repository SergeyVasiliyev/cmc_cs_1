#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int COMPARES = 0;
int SWAPS = 0;

int cmp(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

int cmp2(const void *a, const void *b){
    return(*(int*)b - *(int*)a);
}

void psort(int *a, int n){ // сортировка пузырьком
    int tmp = 0;
    // проходимся по всему массиву, сравниваем элементы подряд
    for (int i = n - 1; i >= 0; i--){
        // так как за каждый проход хотя бы один элемент встает на свое место (слева), то перебираем j < i
        for (int j = 0; j < i; j++){
            COMPARES++;
            if (a[j] > a[j + 1])
            {
                SWAPS++;
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void shsort(int *a, int n){ // сортировка Шелла
    int i, j, step; // берем шаги в степени двойки, каждый раз уменьшаем в раза
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            // проходим по массиву, сравнивая элементы, разность которых равна шагу
            for (j = i; j >= step; j -= step)
            {
                COMPARES++;
                if (tmp < a[j - step]){
                    SWAPS++;
                    a[j] = a[j - step];
                }
                else
                    break;
            }
            a[j] = tmp;
        }
}

void arr1(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = rand();
    }
    qsort(a, n, sizeof(int), cmp);
}

void arr2(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = rand();
    }
    qsort(a, n, sizeof(int), cmp2);
}

void arr3(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = rand();
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    int *a, *b;

    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    arr1(a, n);
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    shsort(a, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    psort(b, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    free(a);
    free(b);

    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    arr2(a, n);
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    shsort(a, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    psort(b, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    free(a);
    free(b);

    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    arr3(a, n);
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    shsort(a, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    psort(b, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    free(a);
    free(b);

    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    arr3(a, n);
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    shsort(a, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    psort(b, n);
    printf("%d %d\n", COMPARES, SWAPS);
    COMPARES = 0;
    SWAPS = 0;
    free(a);
    free(b);
    return 0;
}
