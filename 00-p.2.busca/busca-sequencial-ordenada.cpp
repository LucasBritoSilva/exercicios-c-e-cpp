/*
 * Busca sequencial em vetor ordenado
 * ---------------------------------------------------------------------------
 * Objetivo : em um vetor ORDENADO (crescente), encontrar a posição k do
 *            primeiro elemento maior ou igual a x (se todos forem menores
 *            que x, k = n). Assim, k é a posição onde x está (se existir) ou
 *            onde x deveria ser inserido para manter o vetor ordenado.
 * Entrada  : o número x (o vetor está fixo no código: 10 20 20 30 40).
 * Saída    : a posição k e o que ela significa (a contagem começa em 0).
 * Exemplo  : Entrada: 20 -> k = 1: 20 foi encontrado nessa posicao.
 *            Entrada: 25 -> k = 3: 25 nao esta no vetor; seria inserido nessa posicao.
 *            Entrada: 50 -> k = 5: 50 nao esta no vetor; seria inserido nessa posicao.
 * Compilar : g++ -std=c++11 -Wall -Wextra busca-sequencial-ordenada.cpp -o busca-sequencial-ordenada
 * Executar : ./busca-sequencial-ordenada   (Windows: busca-sequencial-ordenada.exe)
 */

#include <iostream>
using namespace std;

// Devolve a posição do primeiro elemento >= x (ou n, se todos forem menores que x).
// Pré-condição: v[0..n-1] está em ordem crescente.
int busca_ordenada(int v[], int n, int x) {
    int k = 0;
    while (k < n && v[k] < x) {         // avança enquanto os elementos forem menores que x
        k++;
    }
    return k;
}

int main() {
    int v[] = {10, 20, 20, 30, 40};     // vetor ORDENADO usado na busca (com um valor repetido)
    int n = 5;
    int x;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Digite o numero que deseja procurar: ";
    cin >> x;

    int k = busca_ordenada(v, n, x);

    if (k < n && v[k] == x) {
        cout << "k = " << k << ": " << x << " foi encontrado nessa posicao." << endl;
    } else {
        cout << "k = " << k << ": " << x << " nao esta no vetor; seria inserido nessa posicao." << endl;
    }

    return 0;
}