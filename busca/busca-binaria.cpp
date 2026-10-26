/*
 * Busca binária em vetor ordenado
 * ---------------------------------------------------------------------------
 * Objetivo : verificar se um número existe em um vetor ORDENADO (crescente),
 *            dividindo a região de busca ao meio a cada passo.
 *            Invariante do laço: v[esq] < x <= v[dir], com esq = -1 e dir = n
 *            nas extremidades (posições imaginárias antes e depois do vetor).
 * Entrada  : o número x que deseja procurar (o vetor está fixo no código:
 *            1 3 5 7 9 11 13).
 * Saída    : informa se x foi encontrado ou não.
 * Exemplo  : Entrada: 7  ->  7 foi encontrado no vetor.
 *            Entrada: 8  ->  8 nao foi encontrado no vetor.
 * Compilar : g++ -std=c++11 -Wall -Wextra busca-binaria.cpp -o busca-binaria
 * Executar : ./busca-binaria   (Windows: busca-binaria.exe)
 */

#include <iostream>
using namespace std;

// Devolve true se x está em v[0..n-1]. Pré-condição: v está em ordem crescente.
bool busca_binaria(int v[], int n, int x) {
    int esq = -1;                       // v[esq] < x  (-1 = "antes" do vetor)
    int dir = n;                        // x <= v[dir] (n = "depois" do vetor)

    while (esq < dir - 1) {
        int meio = (esq + dir) / 2;
        if (v[meio] < x) {
            esq = meio;                 // x está à direita de meio
        } else {
            dir = meio;                 // x está em meio ou à esquerda
        }
    }

    // dir é a menor posição com v[dir] >= x; só resta conferir se é igual a x
    return dir < n && v[dir] == x;
}

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13};  // vetor ORDENADO usado na busca
    int n = 7;
    int x;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Digite o numero que deseja procurar: ";
    cin >> x;

    if (busca_binaria(v, n, x)) {
        cout << x << " foi encontrado no vetor." << endl;
    } else {
        cout << x << " nao foi encontrado no vetor." << endl;
    }

    return 0;
}