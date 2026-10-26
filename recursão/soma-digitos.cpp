/*
 * Soma dos dígitos de um número — recursivo
 * ---------------------------------------------------------------------------
 * Objetivo : somar os dígitos de um inteiro não negativo. O último dígito é
 *            n % 10 e o restante do número é n / 10; a soma é o último dígito
 *            mais a soma dos dígitos do restante.
 * Entrada  : um número inteiro n >= 0.
 * Saída    : a soma dos dígitos de n.
 * Exemplo  : Entrada: 12345  ->  Saída: Soma dos digitos de 12345 = 15
 * Compilar : g++ -std=c++11 -Wall -Wextra soma-digitos.cpp -o soma-digitos
 * Executar : ./soma-digitos   (Windows: soma-digitos.exe)
 */

#include <iostream>
using namespace std;

// Devolve a soma dos dígitos de n. Pré-condição: n >= 0.
int soma_digitos(int n) {
    if (n / 10 == 0) {                  // só resta um dígito: ele mesmo é a soma
        return n;
    }
    return n % 10 + soma_digitos(n / 10);
}

int main() {
    int n;

    cout << "Digite um numero inteiro maior ou igual a 0: ";
    while (!(cin >> n) || n < 0) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite um inteiro maior ou igual a 0: ";
    }

    cout << "Soma dos digitos de " << n << " = " << soma_digitos(n) << endl;

    return 0;
}