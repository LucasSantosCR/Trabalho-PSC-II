#include <iostream>
using namespace std;

long comparacoes = 0;   // quantas vezes comparou dois elementos
long trocas = 0;        // aqui conta cada deslocamento de elemento

void imprimir(int arr[], int ini, int fim) {
    cout << "[";                                // abre o colchete
    for (int i = ini; i <= fim; i++) {          // vai de ini até fim
        cout << arr[i];                         // mostra o elemento
        if (i < fim) cout << ", ";              // vírgula entre os elementos
    }
    cout << "]" << endl;                        // fecha e pula linha
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {               // arr[0] sozinho já está ordenado
        int chave = arr[i];                     // elemento que vai ser inserido
        int j = i - 1;                          // começa olhando o da esquerda
        while (j >= 0) {                        // enquanto não passou do início
            comparacoes++;                      // vai comparar arr[j] com a chave
            if (arr[j] > chave) {               // o da esquerda é maior que a chave?
                arr[j + 1] = arr[j];            // empurra ele uma casa para a direita
                trocas++;                       // conta o deslocamento
                j--;                            // passa para o próximo da esquerda
            } else {
                break;                          // achou o lugar da chave
            }
        }
        arr[j + 1] = chave;                     // coloca a chave no lugar certo
        cout << "insercao " << i << ": ";       // mostra o array depois de inserir
        imprimir(arr, 0, n - 1);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};             // entrada do teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);       // quantidade de elementos

    cout << "entrada: ";
    imprimir(arr, 0, n - 1);

    insertionSort(arr, n);                      // ordena

    cout << "saida: ";
    imprimir(arr, 0, n - 1);
    cout << "comparacoes: " << comparacoes << endl;
    cout << "trocas: " << trocas << endl;
    return 0;
}
