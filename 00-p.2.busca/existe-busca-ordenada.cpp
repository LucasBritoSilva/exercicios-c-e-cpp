/*
 * Existe? — busca binária que devolve 1 ou 0
 * ---------------------------------------------------------------------------
 * Objetivo : dizer se o número x existe em um vetor ORDENADO (crescente) usando
 *            busca binária. A função existe() devolve 1 (existe) ou 0 (não
 *            existe). É o mesmo algoritmo de busca-binaria.cpp, mudando apenas
 *            o tipo do retorno e a ordem dos parâmetros.
 * Entrada  : o número x (o vetor está fixo no código: 2 4 6 8 10 12 14).
 * Saída    : informa se x existe e qual valor existe() devolveu.
 * Exemplo  : Entrada: 8  ->  8 existe no vetor (existe() devolveu 1).
 *            Entrada: 5  ->  5 nao existe no vetor (existe() devolveu 0).
 * Compilar : g++ -std=c++11 -Wall -Wextra existe-busca-binaria.cpp -o existe-busca-binaria
 * Executar : ./existe-busca-binaria   (Windows: existe-busca-binaria.exe)
 */

#include <iostream>
using namespace std;

// Devolve 1 se x está em v[0..n-1] e 0 caso contrário.
// Pré-condição: v está em ordem crescente.
int existe(int n, int v[], int x) {
    int esq = -1;                       // v[esq] < x  (-1 = "antes" do vetor)
    int dir = n;                        // x <= v[dir] (n = "depois" do vetor)

    while (esq < dir - 1) {
        int meio = (esq + dir) / 2;
        if (v[meio] < x) {
            esq = meio;
        } else {
            dir = meio;
        }
    }

    if (dir < n && v[dir] == x) {
        return 1;
    }
    return 0;
}

int main() {
    int v[] = {2, 4, 6, 8, 10, 12, 14}; // vetor ORDENADO usado na busca
    int n = 7;
    int x;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Digite o numero que deseja procurar: ";
    cin >> x;

    if (existe(n, v, x) == 1) {
        cout << x << " existe no vetor (existe() devolveu 1)." << endl;
    } else {
        cout << x << " nao existe no vetor (existe() devolveu 0)." << endl;
    }

    return 0;
}