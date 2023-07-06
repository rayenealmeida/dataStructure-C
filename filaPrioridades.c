#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *prim;//primriro
    //se tem um ponteiro direto para o fim da fila não será necessário percorrer a fila para inserir uma elemento novo na fila
    No *fim;
    int tam;

}Fila;

void criar_fila(Fila *fila){
    fila -> prim =NULL;
    fila -> fim = NULL;
    fila -> tam = 0;
}

void inserir_na_fila(Fila *fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo =NULL;
        if(fila ->prim==NULL){
            fila->prim = novo;
            fila -> fim = novo;//primrio e ultimo são o mesmo porque temos um só


        }
        else{
            //inserir no fim da fila
            fila->fim->proximo =novo;
            //o ultimo nó ja é outro entao
            //o fim da fila é o que acabei de inserir
            fila->fim=novo;
           
        }
        fila->tam++;//independente se tiver vazia ou não
    }
    else{ printf("\nErro ao alocar memoria.\n");
    }
}

No*  remover_da_fila(Fila *fila){
    No *remover = NULL;//inicializa com null
    //verificar se esta fazia
    if(fila->prim){
        remover = fila->prim;
        //fila vai diminuir uma unidade
        fila->prim = remover -> proximo;
        fila->tam--;//remove então diminui
    }else{
        printf("\tFila vazia\n");
    }
    return remover;
}

void imprimir(Fila *fila){
    No *aux = fila->prim;
    printf("\t------FILA------\n");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux -> proximo;
    }
    printf("\t------FIM FILA------\n");
}
    
int main(){
    No *r;
    Fila fila;
    int opcao, valor;

    criar_fila(&fila);

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                printf("Removido: %d\n", r -> valor);
                free(r);
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        default:
            if(opcao != 0){
                printf("\nOpção inválida!\n");
            }
        }
    }while(opcao != 0);

}