/*
 * Merge Sort em ordem DECRESCENTE
 * ---------------------------------------------------------------------------
 * Objetivo : ordenar o vetor {8, 3, 6, 2, 7, 1, 5, 4} do MAIOR para o MENOR
 *            com o Merge Sort: o vetor é dividido ao meio, cada metade é
 *            ordenada recursivamente e as duas são intercaladas. Diferente de
 *            merge-sort.cpp, aqui a intercalação escolhe sempre o MAIOR dos
 *            dois elementos comparados.
 * Entrada  : nenhuma (o vetor está fixo no código).
 * Saída    : o vetor antes e depois da ordenação.
 * Exemplo  : Antes:  8 3 6 2 7 1 5 4
 *            Depois: 8 7 6 5 4 3 2 1
 * Compilar : g++ -std=c++11 -Wall -Wextra merge-sort-decrescente.cpp -o merge-sort-decrescente
 * Executar : ./merge-sort-decrescente   (Windows: merge-sort-decrescente.exe)
 */

#include <iostream>
#include <vector>
using namespace std;

// Intercala v[inicio..meio] e v[meio+1..fim] (cada trecho já em ordem decrescente)
// de modo que v[inicio..fim] fique em ordem decrescente.
void merge(int v[], int inicio, int meio, int fim) {
    vector<int> aux(fim - inicio + 1);   // vetor auxiliar que guarda o resultado
    int i = inicio;                      // percorre a metade esquerda
    int j = meio + 1;                    // percorre a metade direita
    int k = 0;                           // posição de escrita em aux

    while (i <= meio && j <= fim) {
        if (v[i] > v[j]) {               // o MAIOR dos dois vem primeiro
            aux[k] = v[i];
            k++;
            i++;
        } else {
            aux[k] = v[j];
            k++;
            j++;
        }
    }
    while (i <= meio) {                  // sobrou algo na metade esquerda: copia
        aux[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim) {                   // sobrou algo na metade direita: copia
        aux[k] = v[j];
        j++;
        k++;
    }
    for (int a = 0; a < (fim - inicio + 1); a++) {   // copia o resultado de volta para v
        v[inicio + a] = aux[a];
    }
}

// Ordena v[inicio..fim] em ordem decrescente (Merge Sort recursivo).
void mergeSort(int v[], int inicio, int fim) {
    if (inicio >= fim) {                 // caso base: 0 ou 1 elemento
        return;
    }
    int meio = (inicio + fim) / 2;
    mergeSort(v, inicio, meio);          // ordena a metade esquerda
    mergeSort(v, meio + 1, fim);         // ordena a metade direita
    merge(v, inicio, meio, fim);         // junta as duas metades
}

// Mostra os n elementos do vetor em uma linha.
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int v[] = {8, 3, 6, 2, 7, 1, 5, 4};
    int n = 8;

    cout << "Antes:  ";
    imprimir(v, n);

    mergeSort(v, 0, n - 1);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}