#include <stdio.h>

// Função para realizar a busca binária
int buscaBinaria(int *v, int n, int x) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] < x) {
            inicio = meio + 1; // Se o elemento no meio for menor que x, descarta a metade inferior do array
        } else if (v[meio] > x) {
            fim = meio - 1; // Se o elemento no meio for maior que x, descarta a metade superior do array
        } else {
            return meio; // Elemento encontrado, retorna o índice
        }
    }

    return inicio; // Elemento não encontrado, retorna o índice onde ele deveria ser inserido
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int conjunto[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &conjunto[i]);
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);

        int j = buscaBinaria(conjunto, N, x); // Chama a função buscaBinaria para encontrar o índice j

        printf("%d\n\n\n", j); // Imprime o índice j
    }

    return 0;
}
