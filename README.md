# Algoritmos de Ordenação (PSC II)

Bubble, Selection, Insertion, Merge e Quick Sort em C++, cada um contando comparações e trocas.
Os testes de mesa estão em `testes_de_mesa.pdf`.

## Como rodar

    g++ -std=c++17 -o bubble 01_bubble_sort.cpp && ./bubble

Troque o arquivo para rodar os outros. A entrada de cada programa é `{5, 2, 9, 1, 7, 3}`
e a saída mostra o array depois de cada passada, o resultado final e os contadores.

## Resultado com a entrada de teste

| Algoritmo | Comparações | Trocas |
|-----------|-------------|--------|
| Bubble    | 14          | 8      |
| Selection | 15          | 2      |
| Insertion | 11          | 8      |
| Merge     | 11          | 16     |
| Quick     | 9           | 4      |

## O que conta como troca

- Bubble, Selection e Quick: cada troca real entre dois elementos (troca com ele mesmo não conta).
- Insertion: cada deslocamento `arr[j+1] = arr[j]`.
- Merge: cada escrita no array durante a intercalação.

O Quick Sort usa o último elemento como pivô para o resultado ser sempre o mesmo no teste de mesa.
