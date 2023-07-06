#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo =NULL;
        if(*fila ==NULL){
            *fila = novo;
        }
        else{
            aux = *fila;
            while(aux->proximo)
                aux= aux ->proximo;
            aux-> proximo =novo;
        }
    }
    else{ printf("\nErro ao alocar memoria.\n");
    }
}

No*  remover_da_fila(No **fila){
    No *remover = NULL;//inicializa com null
    //verificar se esta fazia
    if(*fila){
        remover = *fila;
        //fila vai diminuir uma unidade
        *fila = remover -> proximo;
    }else{
        printf("\nFila vazia\n");
        return remover;
    }
}
    
int main(){
    No *fila = NULL;

}