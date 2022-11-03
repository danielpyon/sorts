#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: sorts [...]\n");
        exit(1);
    }

    int n = argc - 1;
    int* list = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        list[i] = atoi(argv[i + 1]);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);

    free(list);
}
