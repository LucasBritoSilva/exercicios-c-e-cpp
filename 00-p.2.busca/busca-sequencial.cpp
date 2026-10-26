/*
 * Busca sequencial (do fim para o início)
 * ---------------------------------------------------------------------------
 * Objetivo : procurar x em um vetor percorrendo-o do último elemento para o
 *            primeiro. Devolve a posição da ÚLTIMA ocorrência de x ou -1 se x
 *            não existir. Não exige que o vetor esteja ordenado.
 * Entrada  : o número x que deseja procurar (o vetor está fixo no código:
 *            4 8 15 16 23 42).
 * Saída    : a posição em que x foi encontrado (a contagem começa em 0) ou
 *            aviso de que ele não está no vetor.
 * Exemplo  : Entrada: 23  ->  23 foi encontrado na posicao 4.
 *            Entrada: 99  ->  99 nao foi encontrado no vetor.
 * Compilar : g++ -std=c++11 -Wall -Wextra busca-sequencial.cpp -o busca-sequencial
 * Executar : ./busca-sequencial   (Windows: busca-sequencial.exe)
 */

#include <iostream>
using namespace std;

// Devolve a posição da última ocorrência de x em v[0..n-1], ou -1 se x não existir.
int busca_sequencial(int v[], int n, int x) {
    int k = n - 1;
    while (k >= 0 && v[k] != x) {       // recua enquanto não achar x
        k--;
    }
    return k;                           // k == -1 quando percorreu tudo sem achar x
}

int main() {
    int v[] = {4, 8, 15, 16, 23, 42};
    int n = 6;
    int x;

    cout << "Vetor: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Digite o numero que deseja procurar: ";
    cin >> x;

    int posicao = busca_sequencial(v, n, x);

    if (posicao >= 0) {
        cout << x << " foi encontrado na posicao " << posicao << " (a contagem comeca em 0)." << endl;
    } else {
        cout << x << " nao foi encontrado no vetor." << endl;
    }

    return 0;
}