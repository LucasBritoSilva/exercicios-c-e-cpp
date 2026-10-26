/*
 * Merge Sort (ordenação por intercalação)
 * ---------------------------------------------------------------------------
 * Objetivo : ordenar um vetor de inteiros em ordem CRESCENTE. O vetor é
 *            dividido ao meio, cada metade é ordenada recursivamente e as duas
 *            metades ordenadas são intercaladas (merge) com um vetor auxiliar.
 * Entrada  : nenhuma (o vetor de teste está fixo no código).
 * Saída    : o vetor antes e depois da ordenação.
 * Exemplo  : Antes:  5 2 8 1 4
 *            Depois: 1 2 4 5 8
 * Compilar : g++ -std=c++11 -Wall -Wextra merge-sort.cpp -o merge-sort
 * Executar : ./merge-sort   (Windows: merge-sort.exe)
 */

#include <iostream>
using namespace std;

// Intercala as duas metades já ordenadas: v[inicio..meio] e v[meio+1..fim]
void merge(int v[], int aux[], int inicio, int meio, int fim) {
    int i = inicio;        // percorre a metade esquerda
    int j = meio + 1;      // percorre a metade direita
    int k = inicio;        // posição de escrita no vetor auxiliar

    // enquanto as duas metades ainda tiverem elementos
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {        // o menor (ou igual, da esquerda) vem primeiro
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    // sobrou algo na metade esquerda? copia
    while (i <= meio) {
        aux[k] = v[i];
        i++;
        k++;
    }

    // sobrou algo na metade direita? copia
    while (j <= fim) {
        aux[k] = v[j];
        j++;
        k++;
    }

    // copia o resultado de volta para o vetor original
    for (int p = inicio; p <= fim; p++) {
        v[p] = aux[p];
    }
}

// Ordena v[inicio..fim] em ordem crescente (Merge Sort recursivo)
void mergeSort(int v[], int aux[], int inicio, int fim) {
    if (inicio >= fim) {                      // caso base: 0 ou 1 elemento
        return;
    }
    int meio = (inicio + fim) / 2;
    mergeSort(v, aux, inicio, meio);          // ordena a metade esquerda
    mergeSort(v, aux, meio + 1, fim);         // ordena a metade direita
    merge(v, aux, inicio, meio, fim);         // junta as duas metades ordenadas
}

// Imprime os elementos do vetor
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 5;
    int v[n] = {5, 2, 8, 1, 4};
    int aux[n];                               // vetor auxiliar do mesmo tamanho

    cout << "Antes:  ";
    imprimir(v, n);

    mergeSort(v, aux, 0, n - 1);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}