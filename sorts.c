#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selection_sort(int* list, int n) {
    for (int i = 0; i < n; i++) {
        int* min = &list[i];
        for (int j = i + 1; j < n; j++)
            if (list[j] < *min)
                min = &list[j];
        swap(min, &list[i]);
    }
}

void bubble_sort(int* list, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (list[j] > list[j + 1])
                swap(&list[j], &list[j + 1]);
}

void insertion_sort(int* list, int n) {
    for (int i = 1; i < n; i++)
        if (list[i - 1] > list[i]) {
            int j = i;
            while (j > 0 && list[j - 1] > list[j]) {
                swap(&list[j], &list[j - 1]);
                j--;
            }
        }
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: sorts [...]\n");
        exit(1);
    }

    int n = argc - 1;
    int* list = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        list[i] = atoi(argv[i + 1]);

    insertion_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);

    free(list);
}
