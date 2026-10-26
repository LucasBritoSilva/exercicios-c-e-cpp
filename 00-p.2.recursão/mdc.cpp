/*
 * Máximo divisor comum (MDC) pelo algoritmo de Euclides — recursivo
 * ---------------------------------------------------------------------------
 * Objetivo : calcular o MDC de dois inteiros positivos. O algoritmo de Euclides
 *            usa o fato de que mdc(x, n) = mdc(n, x % n), parando quando o
 *            resto da divisão é zero.
 * Entrada  : dois inteiros positivos x e n, separados por espaço ou Enter.
 * Saída    : o MDC de x e n.
 * Exemplo  : Entrada: 12 8  ->  Saída: MDC(12, 8) = 4
 * Compilar : g++ -std=c++11 -Wall -Wextra mdc.cpp -o mdc
 * Executar : ./mdc   (Windows: mdc.exe)
 */

#include <iostream>
using namespace std;

// Devolve o MDC de x e n. Pré-condição: x >= 1 e n >= 1.
int mdc(int x, int n) {
    if (n > x) {                        // garante x >= n trocando os valores
        int a = n;
        n = x;
        x = a;
    }
    int r = x % n;                      // resto da divisão de x por n
    if (r == 0) {                       // divisão exata: n é o MDC
        return n;
    }
    return mdc(n, r);
}

int main() {
    int x, n;

    cout << "Digite dois numeros inteiros positivos (x e n), separados por espaco: ";
    while (!(cin >> x >> n) || x < 1 || n < 1) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valores invalidos. Digite dois inteiros positivos: ";
    }

    cout << "MDC(" << x << ", " << n << ") = " << mdc(x, n) << endl;

    return 0;
}