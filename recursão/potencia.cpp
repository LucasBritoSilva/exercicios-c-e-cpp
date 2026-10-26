/*
 * Potência: versão iterativa e versão recursiva
 * ---------------------------------------------------------------------------
 * Objetivo : calcular x elevado a n de duas formas — com um laço (iterativa) e
 *            com recursão (x^n = x * x^(n-1)) — e mostrar os dois resultados.
 *            Para uma versão com menos multiplicações, veja potencia-eficiente.cpp.
 * Entrada  : 1) a base x (número inteiro);
 *            2) o expoente n (inteiro maior ou igual a 0).
 *            O resultado precisa caber em um long long (cerca de 9,2 x 10^18).
 * Saída    : x^n calculado pelas duas versões.
 * Exemplo  : Entrada: base 2, expoente 10
 *            Saída:   Versao iterativa: 2^10 = 1024
 *                     Versao recursiva: 2^10 = 1024
 * Compilar : g++ -std=c++11 -Wall -Wextra potencia.cpp -o potencia
 * Executar : ./potencia   (Windows: potencia.exe)
 */

#include <iostream>
using namespace std;

// Versão com laço: multiplica x por ele mesmo n vezes. Pré-condição: n >= 0.
long long potencia_iterativa(long long x, int n) {
    long long resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= x;
    }
    return resultado;
}

// Versão recursiva: x^n = x * x^(n-1), com x^0 = 1. Pré-condição: n >= 0.
long long potencia_recursiva(long long x, int n) {
    if (n == 0) {                       // caso base
        return 1;
    }
    return x * potencia_recursiva(x, n - 1);
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

    cout << "Versao iterativa: " << x << "^" << n << " = " << potencia_iterativa(x, n) << endl;
    cout << "Versao recursiva: " << x << "^" << n << " = " << potencia_recursiva(x, n) << endl;

    return 0;
}