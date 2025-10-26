1. Alocação estática de memória para um conjunto de elementos significa saber o tamanho do conjunto e também estar certificado que não ocorrerão muitas alterações (inserções e remoções). Quanto ao modo em que os elementos são armazenados, na estrutura estática, eles são armazenados sequencialmente "um ao lado do outro", é possível acessá-los diretamente pelo índice do elemento buscado.

2. Alocação estática tem tamanho definido antes da execução(tempo de compilação), aloca os dados "lado a lado", o que a possibilita acessar os elementos de modo direto e também ser rápida, sendo indicada para quando se sabe o tamanho dos dados e que ocorrerão poucas alterações (inserções e remoções).
Alocação dinâmica tem o tamanho definido após a compilação (tempo de execução), os elementos estão "conectados" por ponteiros o que acarreta num uso maior de memória, não possibilita o acesso aos elementos diretamente, tornando-a lenta mas com tamanho flexível que permite alterações menos trabalhosas (inserções e remoções), indicada para quando não se sabe o tamanho de dados e quando é previsto um fluxo de modificações maior.

3. Um ponteiro é um tipo de variável que armazena um endereço de memória, identificado pela declaração (tipo *ponteiro -> ex: int *p), para receber o endereço de memória é usado "&" antes da variável que se deseja passar o endereço de memória.

4. Uma estrutura de dados homogênea tem apenas um tipo de dado, como, por exemplo, vetores e matrizes, elas armazenam apenas elementos do mesmo tipo de dados.

5. Uma estrutura de dados heterogênea apresenta mais de um tipo de dados, uma struct é um exemplo já que nela se pode armazenar em uma só estrutura, diferentes tipos de dados(inteiros, char, double, entre outros).

6. A principal vantagem no consumo de memória está na forma de alocação de memória, um vetor faz alocação estática, enquanto a lista aloca dinamicamente. 
EX.: É declarado um vetor de tamanho x (v = [100];) para armazenar dados, mas, acabam sendo armazenados menos dados se comparados ao tamanho do vetor (nesse caso, só metade do vetor (50)), isso causa um desperdício de memória pois a memória alocada não está sendo utilizada totalmente. Uma lista não teria esse problema pois aloca em tempo de execução, logo, cresce conforme necessário o que evita o desperdício de memória.

7. Uma lista simplesmente encadeada é formada por nós que armazenam um dado e tem um ponteiro(referência) que aponta para o próximo elemento (nó) da lista.

8. Uma lista duplamente encadeada também é formada por nós, mas com o adicional de um ponteiro para o elemento anterior, aponta para "frente e para trás".

9. questão repetida (igual a questão 8)

10. Para o algoritmo de busca binária é necessário que os elementos estejam ordenados, então são indicados os índices de início e fim, para calcular o meio (início + fim/2) e no decorrer, a cada comparação com o valor buscado é eliminado metade dos elementos até achar ou a lista "acabar", quanto a comparação, valor igual (encontrou o valor), valor procurado é menor (busca continua pela á esquerda), valor procurado é maior(busca segue pela direita).    
- Para o algoritmo de busca sequencial, a leitura começa no primeiro elemento e um após o outro é comparado com o valor procurado até achar ou chegar ao fim da lista.

11. <Insertion sort>: começa pelo segundo elemento, faz a comparação com o elemento anterior (á esquerda) e se o elemento anterior for maior, ele é deslocado para a direita, senão segue para a comparação do próximo elemento, deslocando os elementos maiores para a direita até ordenar os elementos.

<Selection sort>: seleciona o menor elemento e o coloca na primeira posição, em sequência vai selecionando os menores elementos e vai colocando-os na posição correta, segundo menor na segunda posição e assim sucessivamente até a última posição.

- <Merge sort>: consiste em dividir recursivamente a estrutura de dados (como listas, vetores ou arrays) em partes menores até que cada subparte tenha um ou dois elementos, já que ordenar um ou dois elementos é mais simples, depois combina (merge) as subpartes ordenadas, comparando os menores elementos de cada uma e juntando eles em ordem crescente até reconstruir a estrutura original, mas agora ordenada.

- <Count sort>: conta quantas vezes cada valor aparece com o auxílio de um vetor de contagem gerado após encontrar o maior valor e usa essa contagem para reconstruir a lista ordenada.
EX.: o vetor [5,4,3,4,2,2], o maior valor é 5 então cria-se o vetor de contagem e adiciona uma posição para incluir o índice 0, depois inicializa esse vetor de contagem com zeros [0,0,0,0,0,0], para a contagem, em cada índice do vetor de contagem será contado as vezes que o valor (número) do vetor original correspondente aquele índice aparece, seguindo o vetor de exemplo:
índice 0 = 0 ; índice 1 = 0 ; índice 2 = 2 ; índice 3 = 1 ; índice 4 = 2 ; índice 5 = 1, o vetor de contagem fica [0,0,2,1,2,1], e para reconstruir o vetor original de modo ordenado, percorre-se o vetor de contagem do início ao fim (do índice 0 até o maior valor(5)), verificando quantas vezes o valor(índice) aparece e adiciona esse valor à lista ordenada, tantas vezes quanto sua contagem. No caso de exemplo, o vetor ordenado ficaria [2,2,3,4,4,5], os índice que ficaram com zero na contagem não aparecem pois seus valores não fazem parte do vetor original.

- <Quick sort>: escolhe um pivô (elemento da estrutura) e divide a estrutura em dois grupos, 'menores que o pivô' e 'maiores que o pivô', e segue recursivamente (aplica o algoritmo quick sort nos subgrupos) até ordenar os elementos e depois os reúne, primeiro os menores e depois os maiores que o pivô.