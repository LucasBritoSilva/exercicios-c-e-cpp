/*
 * Número de Fibonacci (recursivo)
 * ---------------------------------------------------------------------------
 * Objetivo : calcular o i-ésimo número da sequência de Fibonacci
 *            1, 1, 2, 3, 5, 8, 13, ... (cada termo é a soma dos dois anteriores)
 *            usando recursão: fibonacci(i) = fibonacci(i-1) + fibonacci(i-2),
 *            com fibonacci(1) = fibonacci(2) = 1.
 * Entrada  : a posição i, de 1 a 40. (Limite didático: esta versão recursiva
 *            repete muitos cálculos e fica muito lenta para valores maiores.)
 * Saída    : o valor do i-ésimo número de Fibonacci.
 * Exemplo  : Entrada: 10  ->  Saída: Fibonacci(10) = 55
 * Compilar : g++ -std=c++11 -Wall -Wextra fibonacci.cpp -o fibonacci
 * Executar : ./fibonacci   (Windows: fibonacci.exe)
 */

#include <iostream>
using namespace std;

// Devolve o i-ésimo número de Fibonacci. Pré-condição: i >= 1.
int fibonacci(int i) {
    if (i == 1 || i == 2) {             // casos base
        return 1;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
    int i;

    cout << "Digite a posicao i do numero de Fibonacci (1 a 40): ";
    while (!(cin >> i) || i < 1 || i > 40) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite um numero de 1 a 40: ";
    }

    cout << "Fibonacci(" << i << ") = " << fibonacci(i) << endl;

    return 0;
}