/*
 * Selection Sort — rastreamento da variante "maior no fim"
 * ---------------------------------------------------------------------------
 * Objetivo : mostrar passo a passo uma variante do Selection Sort: em cada
 *            passo procura-se o MAIOR elemento da parte ainda não ordenada e
 *            ele é trocado com o último elemento dessa parte. O resultado é o
 *            vetor em ordem CRESCENTE. (A versão clássica, que leva o MENOR
 *            para o início, está em selection-sort.cpp.)
 * Entrada  : nenhuma (o vetor está fixo no código: 4 7 2 9 5).
 * Saída    : o vetor inicial, o maior encontrado a cada passo e o vetor final.
 * Exemplo  : Vetor inicial: 4 7 2 9 5
 *            Passo 1: maior = 9 (posicao 3) vai para a posicao 4 -> 4 7 2 5 9
 *            Passo 2: maior = 7 (posicao 1) vai para a posicao 3 -> 4 5 2 7 9
 *            Passo 3: maior = 5 (posicao 1) vai para a posicao 2 -> 4 2 5 7 9
 *            Passo 4: maior = 4 (posicao 0) vai para a posicao 1 -> 2 4 5 7 9
 *            Vetor ordenado: 2 4 5 7 9
 * Compilar : g++ -std=c++11 -Wall -Wextra selection-sort-rastreamento-maior-no-fim.cpp -o selection-sort-rastreamento-maior-no-fim
 * Executar : ./selection-sort-rastreamento-maior-no-fim   (Windows: selection-sort-rastreamento-maior-no-fim.exe)
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
    int v[] = {4, 7, 2, 9, 5};
    int n = 5;

    cout << "Vetor inicial: ";
    imprimir(v, n);

    for (int i = 0; i < n - 1; i++) {
        int ultimo = n - 1 - i;                 // última posição da parte ainda não ordenada
        int pos = 0;                            // posição do maior elemento encontrado até agora

        for (int j = 1; j <= ultimo; j++) {     // procura o maior em v[0..ultimo]
            if (v[j] > v[pos]) {
                pos = j;
            }
        }

        int maior = v[pos];                     // guarda o valor para mostrar na mensagem
        int temp = v[pos];                      // troca o maior com o último da parte não ordenada
        v[pos] = v[ultimo];
        v[ultimo] = temp;

        cout << "Passo " << i + 1 << ": maior = " << maior << " (posicao " << pos
             << ") vai para a posicao " << ultimo << " -> ";
        imprimir(v, n);
    }

    cout << "Vetor ordenado: ";
    imprimir(v, n);

    return 0;
}