/*
 * Maior e menor elemento de um vetor (retorno por ponteiros)
 * ---------------------------------------------------------------------------
 * Objetivo : ler uma quantidade de números, guardá-los em um vetor e descobrir
 *            o maior e o menor. A função min_max() devolve os dois resultados
 *            por meio de ponteiros.
 * Entrada  : 1) a quantidade n de números (de 1 a 100);
 *            2) os n números inteiros, separados por espaço ou Enter.
 * Saída    : o maior e o menor elemento.
 * Exemplo  : Entrada:  4
 *                      3 9 -2 7
 *            Saída:    Maior elemento: 9
 *                      Menor elemento: -2
 * Compilar : g++ -std=c++11 -Wall -Wextra maior-menor.cpp -o maior-menor
 * Executar : ./maior-menor   (Windows: maior-menor.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Descobre o maior e o menor de v[0..n-1] e os devolve pelos ponteiros.
// Pré-condição: n >= 1.
void min_max(int n, int v[], int* maior, int* menor) {
    *maior = v[0];
    *menor = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > *maior) {
            *maior = v[i];
        }
        if (v[i] < *menor) {
            *menor = v[i];
        }
    }
}

int main() {
    int n, v[MAX_ELEMENTOS], maior, menor;

    cout << "Digite a quantidade de numeros (1 a " << MAX_ELEMENTOS << "): ";
    while (!(cin >> n) || n < 1 || n > MAX_ELEMENTOS) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Quantidade invalida. Digite um valor de 1 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite os " << n << " numeros inteiros (separados por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    min_max(n, v, &maior, &menor);      // passa o endereço das variáveis que receberão o resultado

    cout << "Maior elemento: " << maior << endl;
    cout << "Menor elemento: " << menor << endl;

    return 0;
}