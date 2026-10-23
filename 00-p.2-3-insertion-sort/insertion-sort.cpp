#include <iostream>
using namespace std;

// Ordena o vetor v de tamanho n em ordem crescente (Insertion Sort)
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {               // i = posição da chave (início da parte não ordenada)
        int chave = v[i];                        // guarda a chave, pois v[i] será sobrescrito
        int j = i - 1;                           // j = último elemento da parte ordenada

        while (j >= 0 && v[j] > chave) {         // enquanto houver elemento maior que a chave
            v[j + 1] = v[j];                     // desloca o elemento uma casa para a direita
            j--;                                 // olha o elemento anterior
        }

        v[j + 1] = chave;                        // insere a chave na posição correta
    }
}

// Imprime os elementos do vetor
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int v[] = {5, 2, 8, 1, 4};
    int n = 5;

    cout << "Antes:  ";
    imprimir(v, n);

    insertionSort(v, n);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}