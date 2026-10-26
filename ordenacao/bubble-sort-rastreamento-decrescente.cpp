/*
 * Bubble Sort — rastreamento (teste de mesa) em ordem DECRESCENTE
 * ---------------------------------------------------------------------------
 * Objetivo : mostrar passo a passo como o Bubble Sort ordena o vetor
 *            {3, 5, 1, 4} do MAIOR para o MENOR (ordem decrescente), contando
 *            as comparações e as trocas. Esta versão não tem parada antecipada:
 *            executa sempre as n-1 passagens.
 * Entrada  : nenhuma (o vetor está fixo no código).
 * Saída    : o vetor após cada passagem e o total de comparações e de trocas.
 * Exemplo  : Vetor inicial: 3 5 1 4
 *            Passagem 1: 5 3 4 1
 *            Passagem 2: 5 4 3 1
 *            Passagem 3: 5 4 3 1
 *            Comparacoes: 6
 *            Trocas: 3
 * Compilar : g++ -std=c++11 -Wall -Wextra bubble-sort-rastreamento-decrescente.cpp -o bubble-sort-rastreamento-decrescente
 * Executar : ./bubble-sort-rastreamento-decrescente   (Windows: bubble-sort-rastreamento-decrescente.exe)
 */

#include <iostream>
using namespace std;

// Mostra os n elementos do vetor em uma linha.
void imprimir(int v[], int n) {
    for (int k = 0; k < n; k++) {
        cout << v[k] << " ";
    }
    cout << endl;
}

int main() {
    int v[] = {3, 5, 1, 4};
    int n = 4;
    int comparacoes = 0;
    int trocas = 0;

    cout << "Vetor inicial: ";
    imprimir(v, n);

    for (int i = 0; i < n - 1; i++) {              // cada passagem leva o MENOR valor restante para o fim
        for (int j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j] < v[j + 1]) {                  // ordem decrescente: troca se o da esquerda é MENOR
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocas++;
            }
        }
        cout << "Passagem " << i + 1 << ": ";
        imprimir(v, n);
    }

    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;

    return 0;
}