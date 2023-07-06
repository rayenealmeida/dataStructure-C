#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct Node {
    int chave;
    struct Node* esquerda;
    struct Node* direita;
};

// Função para criar um novo nó
struct Node* criarNo(int chave) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um novo nó na árvore
struct Node* inserir(struct Node* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void percorrerEmOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    struct Node* raiz = NULL;

    // Exemplo de inserção de elementos
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Exemplo de percurso em ordem (in-order traversal)
    printf("Árvore percorrida em ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    return 0;
}
