/*
 * Bubble Sort com contagem de trocas
 * ---------------------------------------------------------------------------
 * Objetivo : ordenar números inteiros em ordem CRESCENTE com o Bubble Sort
 *            (com parada antecipada) e contar quantas trocas foram feitas.
 * Entrada  : 1) a quantidade n de números (de 1 a 100);
 *            2) os n números inteiros, separados por espaço ou Enter.
 * Saída    : o vetor ordenado e o total de trocas realizadas.
 * Exemplo  : Entrada:  5
 *                      5 4 3 2 1
 *            Saída:    Vetor ordenado: 1 2 3 4 5
 *                      Trocas: 10
 * Compilar : g++ -std=c++11 -Wall -Wextra bubble-sort-contar-trocas.cpp -o bubble-sort-contar-trocas
 * Executar : ./bubble-sort-contar-trocas   (Windows: bubble-sort-contar-trocas.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Ordena v[0..n-1] em ordem crescente e devolve quantas trocas foram feitas.
int bubbleSort(int v[], int n) {
    int trocas = 0;

    for (int i = 0; i < n - 1; i++) {              // cada passagem leva o maior valor restante para o fim
        bool houveTroca = false;                    // nesta passagem ainda não houve troca

        for (int j = 0; j < n - 1 - i; j++) {       // compara pares vizinhos
            if (v[j] > v[j + 1]) {                  // par fora de ordem: troca
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;

                houveTroca = true;
                trocas++;
            }
        }

        if (!houveTroca) {                          // passagem sem trocas: o vetor já está ordenado
            break;
        }
    }

    return trocas;
}

int main() {
    int n;
    int v[MAX_ELEMENTOS];

    cout << "Quantos numeros deseja ordenar (1 a " << MAX_ELEMENTOS << ")? ";
    while (!(cin >> n) || n < 1 || n > MAX_ELEMENTOS) {
        cin.clear();                                // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                     // descarta o restante da linha
        cout << "Valor invalido. Digite uma quantidade de 1 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite os " << n << " numeros inteiros (separados por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int totalTrocas = bubbleSort(v, n);

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl << "Trocas: " << totalTrocas << endl;

    return 0;
}