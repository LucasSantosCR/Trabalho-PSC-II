#include <iostream>
#include <vector>
using namespace std;

long comparacoes = 0;   // quantas vezes comparou dois elementos
long trocas = 0;        // aqui conta cada escrita no array durante a intercalação

void imprimir(int arr[], int ini, int fim) {
    cout << "[";                                // abre o colchete
    for (int i = ini; i <= fim; i++) {          // vai de ini até fim
        cout << arr[i];                         // mostra o elemento
        if (i < fim) cout << ", ";              // vírgula entre os elementos
    }
    cout << "]" << endl;                        // fecha e pula linha
}

void merge(int arr[], int l, int m, int r) {
    int tamL = m - l + 1;                       // tamanho da metade esquerda
    int tamR = r - m;                           // tamanho da metade direita
    vector<int> L(arr + l, arr + m + 1);        // copia a metade esquerda
    vector<int> R(arr + m + 1, arr + r + 1);    // copia a metade direita
    int i = 0, j = 0, k = l;                    // i anda em L, j anda em R, k anda em arr

    while (i < tamL && j < tamR) {              // enquanto as duas metades tem elementos
        comparacoes++;                          // vai comparar L[i] com R[j]
        if (L[i] <= R[j]) {                     // <= mantém a estabilidade
            arr[k] = L[i];                      // o menor é o da esquerda
            i++;                                // avança em L
        } else {
            arr[k] = R[j];                      // o menor é o da direita
            j++;                                // avança em R
        }
        k++;                                    // avança em arr
        trocas++;                               // conta a escrita
    }
    while (i < tamL) {                          // sobrou algo em L
        arr[k] = L[i];                          // copia o que sobrou
        i++;
        k++;
        trocas++;                               // conta a escrita
    }
    while (j < tamR) {                          // sobrou algo em R
        arr[k] = R[j];                          // copia o que sobrou
        j++;
        k++;
        trocas++;                               // conta a escrita
    }
    cout << "merge(l=" << l << ", m=" << m << ", r=" << r << "): ";
    imprimir(arr, l, r);                        // mostra o pedaço intercalado
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {                                // mais de um elemento no intervalo
        int m = l + (r - l) / 2;                // posição do meio
        mergeSort(arr, l, m);                   // ordena a metade esquerda
        mergeSort(arr, m + 1, r);               // ordena a metade direita
        merge(arr, l, m, r);                    // junta as duas metades
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};             // entrada do teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);       // quantidade de elementos

    cout << "entrada: ";
    imprimir(arr, 0, n - 1);

    mergeSort(arr, 0, n - 1);                   // ordena

    cout << "saida: ";
    imprimir(arr, 0, n - 1);
    cout << "comparacoes: " << comparacoes << endl;
    cout << "trocas: " << trocas << endl;
    return 0;
}
