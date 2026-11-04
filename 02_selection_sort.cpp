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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {           // posição que vai receber o menor
        int minIdx = i;                         // começa achando que o menor está em i
        for (int j = i + 1; j < n; j++) {       // procura no resto do array
            comparacoes++;                      // vai comparar arr[j] com o menor atual
            if (arr[j] < arr[minIdx])           // achou um menor ainda?
                minIdx = j;                     // guarda a posição dele
        }
        if (minIdx != i)                        // se o menor já está em i, não precisa trocar
            trocar(arr[i], arr[minIdx]);        // leva o menor para a posição i
        cout << "passada " << i + 1 << ": ";    // mostra o array no fim da passada
        imprimir(arr, 0, n - 1);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};             // entrada do teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);       // quantidade de elementos

    cout << "entrada: ";
    imprimir(arr, 0, n - 1);

    selectionSort(arr, n);                      // ordena

    cout << "saida: ";
    imprimir(arr, 0, n - 1);
    cout << "comparacoes: " << comparacoes << endl;
    cout << "trocas: " << trocas << endl;
    return 0;
}
