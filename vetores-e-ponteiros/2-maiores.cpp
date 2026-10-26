/*
 * Dois maiores elementos de um vetor (retorno por ponteiros)
 * ---------------------------------------------------------------------------
 * Objetivo : ler uma quantidade de números, guardá-los em um vetor e descobrir
 *            o maior e o segundo maior. A função dois_maiores() devolve os dois
 *            resultados por meio de ponteiros. Valores repetidos contam como
 *            elementos diferentes (em 9 9 3, o maior e o segundo maior são 9).
 * Entrada  : 1) a quantidade n de números (de 2 a 100);
 *            2) os n números inteiros, separados por espaço ou Enter.
 * Saída    : o maior número e o segundo maior número.
 * Exemplo  : Entrada:  4
 *                      3 9 7 5
 *            Saída:    O maior numero eh: 9
 *                      O segundo maior numero eh: 7
 * Compilar : g++ -std=c++11 -Wall -Wextra dois-maiores.cpp -o dois-maiores
 * Executar : ./dois-maiores   (Windows: dois-maiores.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Descobre o maior e o segundo maior de v[0..n-1] e os devolve pelos ponteiros.
// Pré-condição: n >= 2.
void dois_maiores(int n, int v[], int* maior, int* segundo) {
    // Começa com os dois primeiros elementos, já na ordem correta.
    if (v[0] >= v[1]) {
        *maior = v[0];
        *segundo = v[1];
    } else {
        *maior = v[1];
        *segundo = v[0];
    }

    for (int i = 2; i < n; i++) {
        if (v[i] > *maior) {            // novo maior: o antigo maior vira o segundo
            *segundo = *maior;
            *maior = v[i];
        } else if (v[i] > *segundo) {   // não é o maior, mas supera o segundo
            *segundo = v[i];
        }
    }
}

int main() {
    int n, v[MAX_ELEMENTOS], maior, segundo;

    cout << "Digite a quantidade de numeros (2 a " << MAX_ELEMENTOS << "): ";
    while (!(cin >> n) || n < 2 || n > MAX_ELEMENTOS) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Quantidade invalida. Digite um valor de 2 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite os " << n << " numeros inteiros (separados por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dois_maiores(n, v, &maior, &segundo);   // passa o endereço das variáveis que receberão o resultado

    cout << "O maior numero eh: " << maior << endl;
    cout << "O segundo maior numero eh: " << segundo << endl;

    return 0;
}