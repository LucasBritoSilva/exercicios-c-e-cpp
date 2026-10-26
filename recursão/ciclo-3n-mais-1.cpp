/*
 * Ciclo 3n+1 (sequência de Collatz)
 * ---------------------------------------------------------------------------
 * Objetivo : dado um inteiro positivo n, gerar a sequência em que, a cada passo,
 *            um valor par é dividido por 2 e um valor ímpar vira 3*valor + 1,
 *            até chegar a 1. Mostra a sequência e quantos números ela tem
 *            (contando o n e o 1), primeiro de forma iterativa e depois recursiva.
 * Entrada  : um número inteiro n >= 1.
 * Saída    : a sequência e a quantidade de números, nas duas versões.
 * Exemplo  : Entrada: 6
 *            Saída:   Versao iterativa: 6 3 10 5 16 8 4 2 1
 *                     Quantidade de numeros: 9
 *                     Versao recursiva: 6 3 10 5 16 8 4 2 1
 *                     Quantidade de numeros: 9
 * Compilar : g++ -std=c++11 -Wall -Wextra ciclo-3n-mais-1.cpp -o ciclo-3n-mais-1
 * Executar : ./ciclo-3n-mais-1   (Windows: ciclo-3n-mais-1.exe)
 */

#include <iostream>
using namespace std;

// Versão iterativa: imprime a sequência e devolve quantos números ela tem.
int ciclo(long long n) {
    int comp = 1;                       // conta o próprio n
    cout << n;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        cout << " " << n;
        comp++;
    }
    cout << endl;
    return comp;
}

// Versão recursiva: imprime a sequência e devolve quantos números ela tem.
int ciclo_recursivo(long long n) {
    cout << n << " ";
    if (n == 1) {                       // caso base: chegou a 1
        cout << endl;
        return 1;
    }
    if (n % 2 == 0) {
        return 1 + ciclo_recursivo(n / 2);
    }
    return 1 + ciclo_recursivo(n * 3 + 1);
}

int main() {
    long long n;

    cout << "Digite um numero inteiro positivo (n >= 1): ";
    while (!(cin >> n) || n < 1) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite um inteiro maior ou igual a 1: ";
    }

    cout << "Versao iterativa: ";
    int quantidade = ciclo(n);
    cout << "Quantidade de numeros: " << quantidade << endl;

    cout << "Versao recursiva: ";
    quantidade = ciclo_recursivo(n);
    cout << "Quantidade de numeros: " << quantidade << endl;

    return 0;
}