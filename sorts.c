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

int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: sorts [...]\n");
        exit(1);
    }

    int n = argc - 1;
    int* list = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        list[i] = atoi(argv[i + 1]);

    bubble_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);

    free(list);
}
