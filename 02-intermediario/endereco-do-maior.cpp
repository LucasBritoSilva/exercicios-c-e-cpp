/*
 * Endereço do maior elemento de um vetor
 * ---------------------------------------------------------------------------
 * Objetivo : ler uma quantidade de números, guardá-los em um vetor e descobrir
 *            onde está o maior. A função maximo() devolve um PONTEIRO para o
 *            maior elemento, isto é, o endereço de memória em que ele está.
 * Entrada  : 1) a quantidade n de números (de 1 a 100);
 *            2) os n números inteiros, separados por espaço ou Enter.
 * Saída    : o maior elemento, a posição dele no vetor (a contagem começa em 0)
 *            e o endereço de memória. O endereço muda a cada execução do programa.
 * Exemplo  : Entrada:  3
 *                      4 9 2
 *            Saída:    Maior elemento: 9
 *                      Posicao no vetor: 1 (a contagem comeca em 0)
 *                      Endereco de memoria: 0x7ffc29f3c224
 * Compilar : g++ -std=c++11 -Wall -Wextra endereco-do-maior.cpp -o endereco-do-maior
 * Executar : ./endereco-do-maior   (Windows: endereco-do-maior.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Devolve o endereço do maior elemento de v[0..n-1]. Pré-condição: n >= 1.
int* maximo(int n, int v[]) {
    int* endereco = &v[0];              // começa supondo que o maior é o primeiro
    for (int i = 1; i < n; i++) {
        if (v[i] > *endereco) {         // achou um valor maior: guarda o endereço dele
            endereco = &v[i];
        }
    }
    return endereco;
}

int main() {
    int n, v[MAX_ELEMENTOS];

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

    int* endereco = maximo(n, v);

    cout << "Maior elemento: " << *endereco << endl;
    cout << "Posicao no vetor: " << (endereco - v) << " (a contagem comeca em 0)" << endl;
    cout << "Endereco de memoria: " << endereco << endl;

    return 0;
}