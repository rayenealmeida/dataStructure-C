#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        // Encontra o índice do elemento mínimo no subarray não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Troca o elemento mínimo com o primeiro elemento não ordenado
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = {9, 5, 1, 8, 3, 10, 2, 7, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    selectionSort(arr, n);

    printf("Array ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
