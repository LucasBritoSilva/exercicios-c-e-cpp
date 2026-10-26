/*
 * Piso do logaritmo na base 2 — recursivo
 * ---------------------------------------------------------------------------
 * Objetivo : calcular o piso de log2(n), isto é, o maior inteiro k tal que
 *            2^k <= n. A ideia: cada divisão inteira de n por 2 corresponde a
 *            um passo; o resultado é quantas divisões são necessárias até n = 1.
 * Entrada  : um número inteiro n >= 1.
 * Saída    : o piso de log2(n).
 * Exemplo  : Entrada: 8   ->  Saída: piso(log2(8)) = 3
 *            Entrada: 10  ->  Saída: piso(log2(10)) = 3
 * Compilar : g++ -std=c++11 -Wall -Wextra piso-log2.cpp -o piso-log2
 * Executar : ./piso-log2   (Windows: piso-log2.exe)
 */

#include <iostream>
using namespace std;

// Devolve o piso de log2(n). Pré-condição: n >= 1.
int piso_log2(int n) {
    if (n / 2 == 0) {                   // n == 1: 2^0 = 1, logo o resultado é 0
        return 0;
    }
    return 1 + piso_log2(n / 2);        // cada divisão por 2 soma 1 ao resultado
}

int main() {
    int n;

    cout << "Digite um numero inteiro n >= 1: ";
    while (!(cin >> n) || n < 1) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite um inteiro maior ou igual a 1: ";
    }

    cout << "piso(log2(" << n << ")) = " << piso_log2(n) << endl;

    return 0;
}