# Merge Sort, ou Ordenação por Intercalação
- é um algoritmo eficiente de ordenação que divide o array em pedaços menores, ordena esses pedaços e, em seguida, combina-os para obter o array final ordenado. Ele segue uma abordagem de dividir para conquistar.

## Descrição passo a passo de como o Merge Sort funciona:

- Divisão: O primeiro passo é dividir o array não ordenado em duas metades aproximadamente iguais. Essa divisão é feita recursivamente até que cada subarray contenha apenas um elemento (pois um único elemento já está ordenado).

- Conquista: Em seguida, cada subarray é ordenado individualmente. Isso pode ser feito chamando recursivamente o Merge Sort nas metades esquerda e direita do array original.

- Combinação: Os subarrays ordenados são mesclados para criar um novo array ordenado. Esse processo é chamado de intercalação. A intercalação envolve comparar os elementos dos subarrays um a um e copiá-los para um novo array na ordem correta. A intercalação continua até que todos os elementos dos subarrays sejam copiados para o novo array.

- Resultado: Após a combinação, o novo array contém todos os elementos do array original, porém em ordem crescente. Esse novo array é o array ordenado final.


### Obs:
O algoritmo de intercalação (combinação) é a chave para o funcionamento eficiente do Merge Sort. Ele requer tempo proporcional ao tamanho total dos subarrays sendo mesclados. A complexidade de tempo do Merge Sort é O(n log n), onde n é o número de elementos no array.