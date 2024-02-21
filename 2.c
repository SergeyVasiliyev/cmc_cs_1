void sort(int *a, int n){ // сортировка Шелла
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
                if (tmp < a[j - step])
                    SWAPS++;
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
}
