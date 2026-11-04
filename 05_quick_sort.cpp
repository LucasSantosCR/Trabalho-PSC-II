#include <iostream>
using namespace std;

long comparacoes = 0;   // quantas vezes comparou dois elementos
long trocas = 0;        // quantas vezes trocou dois elementos de lugar

void trocar(int &a, int &b) {
    int aux = a;        // guarda o valor de a
    a = b;              // a fica com o valor de b
    b = aux;            // b fica com o valor guardado
    trocas++;           // conta a troca
}

void imprimir(int arr[], int ini, int fim) {
    cout << "[";                                // abre o colchete
    for (int i = ini; i <= fim; i++) {          // vai de ini até fim
        cout << arr[i];                         // mostra o elemento
        if (i < fim) cout << ", ";              // vírgula entre os elementos
    }
    cout << "]" << endl;                        // fecha e pula linha
}

int partition(int arr[], int lo, int hi) {
    // pivô fixo no último elemento para o teste de mesa ser sempre igual
    // (na aula foi usado pivô aleatório, dá pra trocar aqui)
    int pivo = arr[hi];                         // valor do pivô
    int i = lo - 1;                             // fim da região dos menores ou iguais ao pivô

    for (int j = lo; j < hi; j++) {             // percorre tudo menos o pivô
        comparacoes++;                          // vai comparar arr[j] com o pivô
        if (arr[j] <= pivo) {                   // pertence à região dos menores?
            i++;                                // a região dos menores cresce uma casa
            if (i != j)                         // não troca elemento com ele mesmo
                trocar(arr[i], arr[j]);         // coloca arr[j] dentro da região
        }
    }
    if (i + 1 != hi)                            // só troca se o pivô não está no lugar
        trocar(arr[i + 1], arr[hi]);            // coloca o pivô na posição final
    return i + 1;                               // posição final do pivô
}

void quickSort(int arr[], int lo, int hi) {
    if (lo < hi) {                              // mais de um elemento no intervalo
        int p = partition(arr, lo, hi);         // particiona e pega a posição do pivô
        cout << "particao(lo=" << lo << ", hi=" << hi << ") pivo="
             << arr[p] << " p=" << p << ": ";
        imprimir(arr, lo, hi);                  // mostra o intervalo depois de particionar
        quickSort(arr, lo, p - 1);              // ordena os menores (esquerda do pivô)
        quickSort(arr, p + 1, hi);              // ordena os maiores (direita do pivô)
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};             // entrada do teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);       // quantidade de elementos

    cout << "entrada: ";
    imprimir(arr, 0, n - 1);

    quickSort(arr, 0, n - 1);                   // ordena

    cout << "saida: ";
    imprimir(arr, 0, n - 1);
    cout << "comparacoes: " << comparacoes << endl;
    cout << "trocas: " << trocas << endl;
    return 0;
}
