/*
 * Soma ou produto? — comparação em pares
 * ---------------------------------------------------------------------------
 * Objetivo : ler uma quantidade PAR de números e analisá-los em pares (1º e 2º,
 *            3º e 4º, ...). Para cada par, a função soma_prod() calcula a soma
 *            e o produto por meio de ponteiros. O programa conta em quantos
 *            pares a soma é maior que o produto e em quantos o produto é maior
 *            que a soma. Pares em que os dois valores são iguais (ex.: 2 e 2)
 *            não entram em nenhuma das contagens.
 * Entrada  : 1) a quantidade de números (par, no mínimo 2);
 *            2) os números inteiros, separados por espaço ou Enter.
 * Saída    : as duas contagens.
 * Exemplo  : Entrada:  4
 *                      2 2 1 5
 *            Saída:    Pares em que a soma eh maior que o produto: 1
 *                      Pares em que o produto eh maior que a soma: 0
 * Compilar : g++ -std=c++11 -Wall -Wextra soma-produto.cpp -o soma-produto
 * Executar : ./soma-produto   (Windows: soma-produto.exe)
 */

#include <iostream>
using namespace std;

// Calcula a soma e o produto de a e b e os devolve pelos ponteiros.
void soma_prod(int a, int b, int* som, int* prod) {
    *som = a + b;
    *prod = a * b;
}

int main() {
    int somas = 0;                      // pares em que a soma é maior que o produto
    int produtos = 0;                   // pares em que o produto é maior que a soma
    int n, a, b, soma, produto;

    cout << "Quantos numeros serao digitados? (deve ser PAR, no minimo 2): ";
    while (!(cin >> n) || n < 2 || n % 2 != 0) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite uma quantidade PAR, no minimo 2: ";
    }

    cout << "Digite os " << n << " numeros inteiros (eles serao lidos em pares: "
         << "1o e 2o, 3o e 4o, ...): ";

    for (int i = 0; i < n / 2; i++) {
        cin >> a >> b;
        soma_prod(a, b, &soma, &produto);
        if (soma > produto) {
            somas++;
        } else if (produto > soma) {
            produtos++;
        }
    }

    cout << "Pares em que a soma eh maior que o produto: " << somas << endl;
    cout << "Pares em que o produto eh maior que a soma: " << produtos << endl;

    return 0;
}