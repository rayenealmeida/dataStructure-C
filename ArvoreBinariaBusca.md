# Árvore binária de busca 
- é uma estrutura de dados hierárquica em que cada nó possui no máximo dois filhos: um à esquerda e outro à direita. Essa estrutura é organizada de forma que para qualquer nó, todos os elementos na subárvore esquerda são menores do que o valor do nó e todos os elementos na subárvore direita são maiores.

## Explicação de como a árvore binária de busca funciona:

1. Inicialmente, a árvore está vazia ou consiste apenas de um nó raiz.

2. Para inserir um novo elemento na árvore, comparamos o valor com o valor do nó atual. Se for menor, vamos para a subárvore esquerda. Se for maior, vamos para a subárvore direita.

3. Repetimos o passo 2 até encontrar uma posição vazia (nó folha) na subárvore correspondente. Nesse ponto, inserimos o novo nó no local apropriado, respeitando a propriedade da árvore binária de busca.

4. Para pesquisar um elemento na árvore, começamos pela raiz e comparamos o valor com o valor do nó atual. Se for igual, encontramos o elemento. Se for menor, vamos para a subárvore esquerda. Se for maior, vamos para a subárvore direita. Repetimos esse processo até encontrar o elemento desejado ou chegar a uma posição vazia (indicando que o elemento não está presente na árvore).

5. Para remover um elemento da árvore, temos três casos a considerar:
        Caso 1: O nó a ser removido é uma folha (não possui filhos). Nesse caso, simplesmente o removemos da árvore.
        Caso 2: O nó a ser removido possui um único filho. Nesse caso, substituímos o nó pelo seu filho.
        Caso 3: O nó a ser removido possui dois filhos. Nesse caso, encontramos o sucessor do nó (o menor elemento na subárvore direita) ou o antecessor (o maior elemento na subárvore esquerda). Substituímos o valor do nó a ser removido pelo valor do sucessor/antecessor e, em seguida, removemos o sucessor/antecessor da subárvore direita/esquerda.

### A árvore binária de busca permite percorrer os elementos em ordem crescente, realizando um percurso em ordem (in-order traversal) que visita primeiro a subárvore esquerda, em seguida, o nó atual e, por fim, a subárvore direita.

## Obs:
- A eficiência da árvore binária de busca depende de sua estrutura balanceada, ou seja, quando as subárvores esquerda e direita têm alturas semelhantes. Isso garante um desempenho de busca, inserção e remoção em tempo médio logarítmico, O(log n), onde "n" é o número de elementos na árvore.