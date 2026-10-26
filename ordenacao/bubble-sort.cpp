/*
 * Bubble Sort (ordenação por bolhas) com parada antecipada
 * ---------------------------------------------------------------------------
 * Objetivo : ordenar um vetor de inteiros em ordem CRESCENTE. A cada passagem,
 *            os vizinhos fora de ordem são trocados e o maior valor restante
 *            "sobe" até o fim. Se uma passagem não fizer nenhuma troca, o vetor
 *            já está ordenado e o programa para antes.
 * Entrada  : nenhuma (o vetor de teste está fixo no código).
 * Saída    : o vetor antes e depois da ordenação.
 * Exemplo  : Antes:  5 2 8 1 4
 *            Depois: 1 2 4 5 8
 * Compilar : g++ -std=c++11 -Wall -Wextra bubble-sort.cpp -o bubble-sort
 * Executar : ./bubble-sort   (Windows: bubble-sort.exe)
 */

#include <iostream>
using namespace std;

// Ordena o vetor v de tamanho n em ordem crescente (Bubble Sort com parada antecipada)
void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {          // controla as passagens
        bool trocou = false;                    // nesta passagem ainda não houve troca

        for (int j = 0; j < n - 1 - i; j++) {   // percorre os pares vizinhos
            if (v[j] > v[j + 1]) {              // par fora de ordem?
                int temp = v[j];                // guarda v[j] para não perdê-lo
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = true;                  // registra que houve troca
            }
        }

        if (!trocou) {                          // passagem sem trocas: já está ordenado
            break;
        }
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

    bubbleSort(v, n);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}