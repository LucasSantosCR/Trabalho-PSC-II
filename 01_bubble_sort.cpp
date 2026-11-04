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

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {           // no máximo n-1 passadas
        bool trocou = false;                    // ainda não trocou nada nesta passada
        for (int j = 0; j < n - i - 1; j++) {   // os últimos i elementos já estão no lugar
            comparacoes++;                      // vai comparar dois vizinhos
            if (arr[j] > arr[j + 1]) {          // o da esquerda é maior?
                trocar(arr[j], arr[j + 1]);     // então troca os dois
                trocou = true;                  // anota que teve troca
            }
        }
        cout << "passada " << i + 1 << ": ";    // mostra o array no fim da passada
        imprimir(arr, 0, n - 1);
        if (!trocou) break;                     // passada sem troca = já está ordenado
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};             // entrada do teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);       // quantidade de elementos

    cout << "entrada: ";
    imprimir(arr, 0, n - 1);

    bubbleSort(arr, n);                         // ordena

    cout << "saida: ";
    imprimir(arr, 0, n - 1);
    cout << "comparacoes: " << comparacoes << endl;
    cout << "trocas: " << trocas << endl;
    return 0;
}
