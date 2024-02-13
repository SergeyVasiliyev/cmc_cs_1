void sort(int *a, int n){
    int tmp = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    return 0;
}
