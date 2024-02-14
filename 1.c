void sort(int *a, int n){ // сортировка пузырьком
    int tmp = 0;
    // проходимся по всему массиву, сравниваем элементы подряд
    for (int i = n - 1; i >= 0; i--){
        // так как за каждый проход хотя бы один элемент встает на свое место (слева), то перебираем j < i
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
