/*
 * Merge Sort — rastreamento (teste de mesa) em ordem CRESCENTE
 * ---------------------------------------------------------------------------
 * Objetivo : mostrar passo a passo as divisões e as intercalações (merge) do
 *            Merge Sort sobre o vetor {7, 3, 9, 1, 6, 2}, contando as comparações.
 * Entrada  : nenhuma (o vetor está fixo no código).
 * Saída    : cada divisão, cada intercalação (com as comparações feitas), o
 *            vetor ordenado e o total de comparações.
 * Exemplo  : (trecho final da saída)
 *            Vetor ordenado: 1 2 3 6 7 9
 *            Total de comparacoes: 10
 * Compilar : g++ -std=c++11 -Wall -Wextra merge-sort-rastreamento.cpp -o merge-sort-rastreamento
 * Executar : ./merge-sort-rastreamento   (Windows: merge-sort-rastreamento.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // tamanho máximo dos vetores auxiliares

int comparacoes = 0;             // total de comparações feitas durante os merges

// Mostra os elementos v[inicio..fim] em uma linha.
void imprimirTrecho(int v[], int inicio, int fim) {
    for (int p = inicio; p <= fim; p++) {
        cout << v[p] << " ";
    }
    cout << endl;
}

// Intercala v[inicio..meio] e v[meio+1..fim] (cada trecho já ordenado), mostrando cada passo.
void merge(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;          // tamanho da metade esquerda
    int n2 = fim - meio;                 // tamanho da metade direita

    int esquerda[MAX_ELEMENTOS];
    int direita[MAX_ELEMENTOS];

    for (int a = 0; a < n1; a++) {
        esquerda[a] = v[inicio + a];
    }
    for (int b = 0; b < n2; b++) {
        direita[b] = v[meio + 1 + b];
    }

    cout << "\nMerge dos trechos [" << inicio << ".." << meio << "] e ["
         << meio + 1 << ".." << fim << "]" << endl;

    cout << "Esquerda: ";
    for (int a = 0; a < n1; a++) {
        cout << esquerda[a] << " ";
    }
    cout << "\nDireita: ";
    for (int b = 0; b < n2; b++) {
        cout << direita[b] << " ";
    }
    cout << endl;

    int i = 0, j = 0, k = inicio;        // i: esquerda, j: direita, k: posição de escrita em v

    while (i < n1 && j < n2) {
        comparacoes++;

        cout << "Comparando " << esquerda[i] << " e " << direita[j] << " -> ";

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

    while (i < n1) {                     // sobrou algo na esquerda: copia
        v[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {                     // sobrou algo na direita: copia
        v[k] = direita[j];
        j++;
        k++;
    }

    cout << "Trecho [" << inicio << ".." << fim << "] apos o merge: ";
    imprimirTrecho(v, inicio, fim);
}

// Ordena v[inicio..fim] em ordem crescente (Merge Sort recursivo), mostrando cada divisão.
void mergeSort(int v[], int inicio, int fim) {
    if (inicio >= fim) {                 // caso base: 0 ou 1 elemento
        return;
    }

    int meio = (inicio + fim) / 2;

    cout << "\nDividindo trecho [" << inicio << ".." << fim << "]"
         << " | meio = " << meio << endl;

    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);

    merge(v, inicio, meio, fim);
}

int main() {
    int v[] = {7, 3, 9, 1, 6, 2};
    int n = 6;

    cout << "Vetor inicial: ";
    imprimirTrecho(v, 0, n - 1);

    mergeSort(v, 0, n - 1);

    cout << "\nVetor ordenado: ";
    imprimirTrecho(v, 0, n - 1);
    cout << "Total de comparacoes: " << comparacoes << endl;

    return 0;
}