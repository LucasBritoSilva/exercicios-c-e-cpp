/*
 * Insertion Sort — rastreamento (teste de mesa) em ordem DECRESCENTE
 * ---------------------------------------------------------------------------
 * Objetivo : mostrar passo a passo como o Insertion Sort ordena o vetor
 *            {3, 8, 5, 9, 1} do MAIOR para o MENOR, contando os deslocamentos
 *            (quantas vezes um elemento foi empurrado uma casa para a direita).
 * Entrada  : nenhuma (o vetor está fixo no código).
 * Saída    : o vetor inicial, o vetor após cada inserção e o total de deslocamentos.
 * Exemplo  : Vetor inicial: 3 8 5 9 1
 *            Passo 1: chave 8 inserida na posicao 0 -> 8 3 5 9 1
 *            Passo 2: chave 5 inserida na posicao 1 -> 8 5 3 9 1
 *            Passo 3: chave 9 inserida na posicao 0 -> 9 8 5 3 1
 *            Passo 4: chave 1 inserida na posicao 4 -> 9 8 5 3 1
 *            Deslocamentos: 5
 * Compilar : g++ -std=c++11 -Wall -Wextra insertion-sort-rastreamento-decrescente.cpp -o insertion-sort-rastreamento-decrescente
 * Executar : ./insertion-sort-rastreamento-decrescente   (Windows: insertion-sort-rastreamento-decrescente.exe)
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
    int v[] = {3, 8, 5, 9, 1};
    int n = 5;
    int deslocamentos = 0;

    cout << "Vetor inicial: ";
    imprimir(v, n);

    for (int i = 1; i < n; i++) {
        int chave = v[i];                           // elemento a inserir na parte já ordenada
        int j = i - 1;

        while (j >= 0 && v[j] < chave) {            // ordem decrescente: empurra os MENORES para a direita
            v[j + 1] = v[j];
            j--;
            deslocamentos++;
        }
        v[j + 1] = chave;                           // coloca a chave na posição correta

        cout << "Passo " << i << ": chave " << chave << " inserida na posicao " << j + 1 << " -> ";
        imprimir(v, n);
    }

    cout << "Deslocamentos: " << deslocamentos << endl;

    return 0;
}