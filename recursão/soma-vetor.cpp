/*
 * Soma dos elementos de um vetor — recursiva
 * ---------------------------------------------------------------------------
 * Objetivo : somar os n primeiros elementos de um vetor de números reais.
 *            A soma de n elementos é o último elemento mais a soma dos n-1
 *            primeiros; com um só elemento, a soma é ele mesmo.
 * Entrada  : 1) a quantidade n de números (de 1 a 100);
 *            2) os n números reais (use PONTO como separador decimal, ex.: 2.5),
 *               separados por espaço ou Enter.
 * Saída    : a soma dos elementos.
 * Exemplo  : Entrada:  3
 *                      1.5 2.5 3
 *            Saída:    Soma dos elementos: 7
 * Compilar : g++ -std=c++11 -Wall -Wextra soma-vetor.cpp -o soma-vetor
 * Executar : ./soma-vetor   (Windows: soma-vetor.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Devolve a soma de v[0..n-1]. Pré-condição: n >= 1.
float soma(float v[], int n) {
    if (n == 1) {                       // caso base: um só elemento
        return v[0];
    }
    float s = v[n - 1];                 // último elemento
    return s + soma(v, n - 1);          // + soma dos n-1 primeiros
}

int main() {
    float v[MAX_ELEMENTOS];
    int n;

    cout << "Quantos numeros deseja somar (1 a " << MAX_ELEMENTOS << ")? ";
    while (!(cin >> n) || n < 1 || n > MAX_ELEMENTOS) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite uma quantidade de 1 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite os " << n << " numeros (use ponto nos decimais; separe por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Soma dos elementos: " << soma(v, n) << endl;

    return 0;
}