/*
 * Potência eficiente (exponenciação rápida) — recursiva
 * ---------------------------------------------------------------------------
 * Objetivo : calcular x elevado a n com poucas multiplicações: se n é par,
 *            x^n = (x^(n/2))^2; se n é ímpar, x^n = x * x^(n-1). Assim o número
 *            de multiplicações cresce com log2(n) e não com n.
 * Entrada  : 1) a base x (número inteiro);
 *            2) o expoente n (inteiro maior ou igual a 0).
 *            O resultado precisa caber em um long long (cerca de 9,2 x 10^18).
 * Saída    : o valor de x^n.
 * Exemplo  : Entrada: base 2, expoente 10  ->  Saída: 2^10 = 1024
 * Compilar : g++ -std=c++11 -Wall -Wextra potencia-eficiente.cpp -o potencia-eficiente
 * Executar : ./potencia-eficiente   (Windows: potencia-eficiente.exe)
 */

#include <iostream>
using namespace std;

// Devolve x elevado a n. Pré-condição: n >= 0.
long long potencia(long long x, int n) {
    if (n == 0) {                       // qualquer número elevado a 0 é 1
        return 1;
    }
    if (n % 2 == 0) {                   // expoente par: calcula a metade e eleva ao quadrado
        long long p = potencia(x, n / 2);
        return p * p;
    }
    return x * potencia(x, n - 1);      // expoente ímpar: tira um fator x e cai no caso par
}

int main() {
    long long x;
    int n;

    cout << "Digite a base x (numero inteiro): ";
    while (!(cin >> x)) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite um numero inteiro: ";
    }

    cout << "Digite o expoente n (inteiro maior ou igual a 0): ";
    while (!(cin >> n) || n < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Valor invalido. Digite um inteiro maior ou igual a 0: ";
    }

    cout << x << "^" << n << " = " << potencia(x, n) << endl;

    return 0;
}