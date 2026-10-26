/*
 * Quick Sort (ordenação rápida)
 * ---------------------------------------------------------------------------
 * Objetivo : ordenar um vetor de inteiros em ordem CRESCENTE. Escolhe-se um
 *            pivô (o último elemento), separam-se os elementos menores ou
 *            iguais a ele dos maiores (particionamento) e cada lado é
 *            ordenado recursivamente.
 * Entrada  : nenhuma (o vetor de teste está fixo no código).
 * Saída    : o vetor antes e depois da ordenação.
 * Exemplo  : Antes:  5 2 8 1 4
 *            Depois: 1 2 4 5 8
 * Compilar : g++ -std=c++11 -Wall -Wextra quick-sort.cpp -o quick-sort
 * Executar : ./quick-sort   (Windows: quick-sort.exe)
 */

#include <iostream>
using namespace std;

// Troca os elementos das posições a e b
void trocar(int v[], int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

// Particiona v[inicio..fim] usando o último elemento como pivô.
// Retorna a posição final do pivô.
int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];                 // pivô = último elemento
    int i = inicio - 1;                // fim da região dos elementos <= pivô (começa vazia)

    for (int j = inicio; j < fim; j++) {   // examina todos, exceto o pivô
        if (v[j] <= pivo) {                // pertence à região dos "menores ou iguais"?
            i++;                           // a região cresce uma posição
            trocar(v, i, j);               // traz v[j] para dentro da região
        }
    }

    trocar(v, i + 1, fim);             // coloca o pivô entre as duas regiões
    return i + 1;                      // posição final (definitiva) do pivô
}

// Ordena v[inicio..fim] em ordem crescente (Quick Sort recursivo)
void quickSort(int v[], int inicio, int fim) {
    if (inicio >= fim) {               // caso base: 0 ou 1 elemento
        return;
    }
    int p = particionar(v, inicio, fim);
    quickSort(v, inicio, p - 1);       // ordena o lado esquerdo do pivô
    quickSort(v, p + 1, fim);          // ordena o lado direito do pivô
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

    quickSort(v, 0, n - 1);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}