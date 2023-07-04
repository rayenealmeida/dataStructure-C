#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char* japones;
    char* portugues;
} Item;

#define key(A) ((A).japones)
#define less(A, B) (strcmp(key(A), key(B)) < 0)
#define exch(A, B) { Item tmp = A; A = B; B = tmp; }
#define cmpexch(A, B) { if (less(A, B)) exch(A, B); }

int partition(Item *v, int begin, int end) {
    int i = begin - 1;
    int j = end;

    for (;;) {
        while (less(v[++i], v[end])) {}

        while (less(v[end], v[--j])) {
            if (j == begin) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        exch(v[i], v[j]);
    }
    exch(v[i], v[end]);
    return i;
}

void quicksort(Item *v, int begin, int end, int recursion) {
    if (begin >= end) {
        return;
    }

    if (recursion == 0) {
        return;
    }

    int mid = (begin + end) / 2;
    cmpexch(v[mid], v[end]);
    cmpexch(v[begin], v[mid]);
    cmpexch(v[end], v[mid]);

    int p = partition(v, begin, end);
    quicksort(v, begin, p - 1, recursion - 1);
    quicksort(v, p + 1, end, recursion - 1);
}

void merge(Item *v, int begin, int mid, int end) {
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    Item *left = malloc(sizeof(Item) * n1);
    Item *right = malloc(sizeof(Item) * n2);

    for (int i = 0; i < n1; i++) {
        left[i] = v[begin + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = v[mid + 1 + j];
    }

    int i = 0, j = 0, k = begin;

    while (i < n1 && j < n2) {
        if (less(left[i], right[j])) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
        }
    }

    while (i < n1) {
        v[k++] = left[i++];
    }

    while (j < n2) {
        v[k++] = right[j++];
    }

    free(left);
    free(right);
}

void mergeSort(Item *v, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;

        mergeSort(v, begin, mid);
        mergeSort(v, mid + 1, end);

        merge(v, begin, mid, end);
    }
}

void insertionSort(Item *v, int begin, int end) {
    for (int i = begin + 1; i <= end; i++) {
        Item keyItem = v[i];
        int j = i - 1;

        while (j >= begin && less(keyItem, v[j])) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = keyItem;
    }
}

void introsort(Item *v, int begin, int end) {
    int maxRecursion = 2 * ((int)log2((double)(end - begin + 1)));

    quicksort(v, begin, end, maxRecursion);

    if ((end - begin + 1) <= 16) {
        insertionSort(v, begin, end);
    } else if (maxRecursion == 0) {
        mergeSort(v, begin, end);
    }
}

int binarySearch(Item *v, int begin, int end, Item target) {
    int mid;

    while (end >= begin) {
        mid = (begin + end) / 2;

        if (less(v[mid], target)) {
            begin = mid + 1;
        } else if (less(target, v[mid])) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void translateLyrics(Item *dictionary, int numWords, char **lyrics, int numLines) {
    for (int i = 0; i < numLines; i++) {
        char *line = lyrics[i];
        char *word = strtok(line, " ");

        while (word != NULL) {
            Item target;
            strcpy(target.japones, word);

            int index = binarySearch(dictionary, 0, numWords - 1, target);

            if (index != -1) {
                printf("%s ", dictionary[index].portugues);
            } else {
                printf("%s ", word);
            }

            word = strtok(NULL, " ");
        }

        printf("\n");
    }
}

int main() {
    int instances;
    scanf("%d", &instances);

    while (instances--) {
        int M, N;
        scanf("%d %d", &M, &N);

        Item* dictionary = malloc(sizeof(Item) * M);
        for (int i = 0; i < M; i++) {
            dictionary[i].japones = malloc(81);
            dictionary[i].portugues = malloc(81);
            scanf(" %[^\n]", dictionary[i].japones);
            scanf(" %[^\n]", dictionary[i].portugues);
        }
        introsort(dictionary, 0, M - 1);

        char **lyrics = malloc(sizeof(char*) * N);
        for (int i = 0; i < N; i++) {
            lyrics[i] = malloc(81);
            scanf(" %[^\n]", lyrics[i]);
        }

        translateLyrics(dictionary, M, lyrics, N);

        printf("\n");

        // Liberar memória alocada
        for (int i = 0; i < M; i++) {
            free(dictionary[i].japones);
            free(dictionary[i].portugues);
        }
        free(dictionary);

        for (int i = 0; i < N; i++) {
            free(lyrics[i]);
        }
        free(lyrics);
    }

    return 0;
}

