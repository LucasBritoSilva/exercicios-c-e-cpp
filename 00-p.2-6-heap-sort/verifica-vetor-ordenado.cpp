/*
 * Verifica se um vetor está ordenado
 * ---------------------------------------------------------------------------
 * Objetivo : ler um vetor de inteiros e informar se os elementos estão em
 *            ordem crescente (cada elemento é maior ou igual ao anterior).
 * Entrada  : 1) a quantidade n de números (de 1 a 100);
 *            2) os n números inteiros, separados por espaço ou Enter.
 * Saída    : "ORDENADO" ou "NAO ORDENADO".
 * Exemplo  : Entrada:  3
 *                      1 2 3
 *            Saída:    Resultado: ORDENADO (ordem crescente)
 *
 *            Entrada:  3
 *                      1 3 2
 *            Saída:    Resultado: NAO ORDENADO
 * Compilar : g++ -std=c++11 -Wall -Wextra verifica-vetor-ordenado.cpp -o verifica-vetor-ordenado
 * Executar : ./verifica-vetor-ordenado   (Windows: verifica-vetor-ordenado.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Devolve true se v[0] <= v[1] <= ... <= v[n-1].
bool verifica(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] < v[i]) {
            return false;                           // achou um par fora de ordem
        }
    }
    return true;
}

int main() {
    int n;
    int v[MAX_ELEMENTOS];

    cout << "Quantos numeros tem o vetor (1 a " << MAX_ELEMENTOS << ")? ";
    while (!(cin >> n) || n < 1 || n > MAX_ELEMENTOS) {
        cin.clear();                                // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                     // descarta o restante da linha
        cout << "Valor invalido. Digite uma quantidade de 1 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite os " << n << " numeros inteiros (separados por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (verifica(v, n)) {
        cout << "Resultado: ORDENADO (ordem crescente)" << endl;
    } else {
        cout << "Resultado: NAO ORDENADO" << endl;
    }

    return 0;
}