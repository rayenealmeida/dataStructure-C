# Selection Sort (Ordenação por Seleção) 
- é um algoritmo de ordenação simples e eficiente. Ele percorre o array várias vezes, dividindo-o em duas partes: uma parte ordenada e outra parte não ordenada. Em cada iteração, ele encontra o menor elemento na parte não ordenada e o coloca na posição correta na parte ordenada. Esse processo continua até que todo o array esteja ordenado.

## Descrição passo a passo de como o Selection Sort funciona:

- Divisão: O array é dividido em duas partes: uma parte ordenada e uma parte não ordenada. Inicialmente, a parte ordenada está vazia e a parte não ordenada contém todos os elementos do array.

- Seleção do menor elemento: O algoritmo percorre a parte não ordenada do array para encontrar o menor elemento. Ele compara cada elemento com o menor elemento encontrado até o momento e, se encontrar um elemento menor, atualiza o menor elemento encontrado.

- Troca: Após encontrar o menor elemento, ele é trocado com o primeiro elemento da parte não ordenada. Assim, o menor elemento fica na posição correta na parte ordenada, e a parte ordenada é expandida para incluí-lo.

- Repetição: Os passos 2 e 3 são repetidos até que a parte não ordenada fique vazia e todo o array esteja ordenado. Em cada iteração, o tamanho da parte não ordenada diminui, enquanto o tamanho da parte ordenada aumenta.

#### Selection Sort é chamado assim porque, em cada iteração, ele "seleciona" o menor elemento não ordenado e o coloca na posição correta.

## Obs:
O tempo de execução do Selection Sort é sempre O(n^2), onde n é o número de elementos no array. Isso ocorre porque, em cada iteração, ele precisa percorrer a parte não ordenada para encontrar o menor elemento. Apesar de não ser o algoritmo mais eficiente em termos de tempo de execução, ele é fácil de entender e implementar, sendo adequado para pequenos conjuntos de dados ou quando a complexidade do código é mais importante do que o desempenho.