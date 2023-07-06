# Bubble Sort
- conhecido como ordenação por bolha, é um algoritmo simples de classificação que funciona comparando repetidamente pares de elementos adjacentes em uma lista e trocando-os se estiverem na ordem errada. Esse processo é repetido várias vezes até que a lista esteja totalmente ordenada.

## Exemplo do funcionamento do Bubble Sort:

- Dada uma lista de elementos não ordenados, o algoritmo começa comparando o primeiro par de elementos adjacentes.

- Se o primeiro elemento for maior que o segundo, eles são trocados de lugar.

- Em seguida, o algoritmo compara o segundo par de elementos adjacentes e continua trocando-os, se necessário.

- Esse processo continua para todos os pares de elementos adjacentes na lista, percorrendo-a do início ao fim.

- Ao final da primeira passagem, o maior elemento estará na posição correta no final da lista.

- Em seguida, o algoritmo repete o mesmo processo para o restante da lista, excluindo o último elemento que já está na posição correta.

- O processo é repetido até que não ocorram mais trocas, o que indica que a lista está totalmente ordenada.

## Exemplo passo a passo do Bubble Sort em ação, usando a lista [5, 2, 9, 1, 3]:

- Passo 1: [5, 2, 9, 1, 3] (5 e 2 são trocados)
- Passo 2: [2, 5, 9, 1, 3] (9 e 1 são trocados)
- Passo 3: [2, 5, 1, 9, 3] (9 e 3 são trocados)
- Passo 4: [2, 5, 1, 3, 9] (não ocorrem trocas)


### Obs:
Neste ponto, a lista está ordenada e o algoritmo termina. O Bubble Sort tem uma complexidade de tempo de O(n^2), o que significa que o tempo de execução aumenta quadraticamente com o tamanho da lista. Isso torna o Bubble Sort ineficiente para listas muito grandes, mas pode ser adequado para listas pequenas ou quase ordenadas, devido à sua simplicidade de implementação.