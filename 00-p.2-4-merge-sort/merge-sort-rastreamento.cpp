
#include <iostream>
using namespace std;

int comparacoes = 0;

void merge(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esquerda[100];
    int direita[100];

    for (int i = 0; i < n1; i++) {
        esquerda[i] = v[inicio + i];
    }

    for (int j = 0; j < n2; j++) {
        direita[j] = v[meio + 1 + j];
    }

    cout << "\nMerge dos trechos: ";
    cout << "[" << inicio << ".." << meio << "] e ";
    cout << "[" << meio + 1 << ".." << fim << "]" << endl;

    cout << "Esquerda: ";
    for (int i = 0; i < n1; i++) {
        cout << esquerda[i] << " ";
    }

    cout << "\nDireita: ";
    for (int j = 0; j < n2; j++) {
        cout << direita[j] << " ";
    }
    cout << endl;

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        comparacoes++;

        cout << "Comparando " << esquerda[i]
             << " e " << direita[j] << " -> ";

        if (esquerda[i] <= direita[j]) {
            v[k] = esquerda[i];
            cout << "escolhe " << esquerda[i] << endl;
            i++;
        } else {
            v[k] = direita[j];
            cout << "escolhe " << direita[j] << endl;
            j++;
        }

        k++;
    }

    while (i < n1) {
        v[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = direita[j];
        j++;
        k++;
    }

    cout << "Vetor apos merge: ";
    for (int p = 0; p < 6; p++) {
        cout << v[p] << " ";
    }
    cout << endl;
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int meio = (inicio + fim) / 2;

    cout << "\nDividindo trecho [" << inicio
         << ".." << fim << "]";
    cout << " | meio = " << meio << endl;

    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);

    merge(v, inicio, meio, fim);
}

int main() {
    int v[] = {7, 3, 9, 1, 6, 2};
    int n = 6;

    cout << "Vetor inicial: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    mergeSort(v, 0, n - 1);

    cout << "\nVetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    cout << "\nTotal de comparacoes: "
         << comparacoes << endl;

    return 0;
}