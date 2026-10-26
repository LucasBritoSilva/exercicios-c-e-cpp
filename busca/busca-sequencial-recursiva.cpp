/*
 * Busca sequencial recursiva
 * ---------------------------------------------------------------------------
 * Objetivo : procurar x em v[i..n-1] de forma recursiva, examinando um
 *            elemento por chamada, da esquerda para a direita. Devolve a
 *            posição da PRIMEIRA ocorrência de x ou -1 se x não existir.
 *            Não exige que o vetor esteja ordenado.
 * Entrada  : o número x que deseja procurar (o vetor está fixo no código:
 *            4 8 15 16 23 42).
 * Saída    : a posição em que x foi encontrado (a contagem começa em 0) ou
 *            aviso de que ele não está no vetor.
 * Exemplo  : Entrada: 23  ->  23 foi encontrado na posicao 4.
 *            Entrada: 99  ->  99 nao foi encontrado no vetor.
 * Compilar : g++ -std=c++11 -Wall -Wextra busca-sequencial-recursiva.cpp -o busca-sequencial-recursiva
 * Executar : ./busca-sequencial-recursiva   (Windows: busca-sequencial-recursiva.exe)
 */

#include <iostream>
using namespace std;

// Procura x a partir da posição i. Devolve a posição de x ou -1 se não encontrar.
int busca_sequencial_recursiva(int v[], int n, int x, int i) {
    if (i == n) {                       // passou do último elemento: não achou
        return -1;
    }

    if (v[i] == x) {                    // achou na posição i
        return i;
    }

    return busca_sequencial_recursiva(v, n, x, i + 1);   // tenta a posição seguinte
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

    int posicao = busca_sequencial_recursiva(v, n, x, 0);   // começa pela posição 0

    if (posicao >= 0) {
        cout << x << " foi encontrado na posicao " << posicao << " (a contagem comeca em 0)." << endl;
    } else {
        cout << x << " nao foi encontrado no vetor." << endl;
    }

    return 0;
}