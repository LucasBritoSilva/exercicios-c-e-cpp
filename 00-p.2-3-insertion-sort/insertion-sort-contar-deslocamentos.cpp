/*
 * Insertion Sort com contagem de deslocamentos
 * ---------------------------------------------------------------------------
 * Objetivo : ordenar números inteiros em ordem CRESCENTE com o Insertion Sort e
 *            contar os deslocamentos (quantas vezes um elemento foi empurrado
 *            uma casa para a direita para abrir espaço para a chave).
 * Entrada  : 1) a quantidade n de números (de 1 a 100);
 *            2) os n números inteiros, separados por espaço ou Enter.
 * Saída    : o vetor ordenado e o total de deslocamentos.
 * Exemplo  : Entrada:  5
 *                      5 4 3 2 1
 *            Saída:    Vetor ordenado: 1 2 3 4 5
 *                      Total de deslocamentos: 10
 * Compilar : g++ -std=c++11 -Wall -Wextra insertion-sort-contar-deslocamentos.cpp -o insertion-sort-contar-deslocamentos
 * Executar : ./insertion-sort-contar-deslocamentos   (Windows: insertion-sort-contar-deslocamentos.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Ordena v[0..n-1] em ordem crescente e devolve o total de deslocamentos.
int insertionSort(int v[], int n) {
    int deslocamentos = 0;

    for (int i = 1; i < n; i++) {
        int chave = v[i];                           // elemento a inserir na parte já ordenada
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {            // abre espaço empurrando os maiores para a direita
            v[j + 1] = v[j];
            j--;
            deslocamentos++;
        }

        v[j + 1] = chave;                           // coloca a chave na posição correta
    }

    return deslocamentos;
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

    int total = insertionSort(v, n);

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl << "Total de deslocamentos: " << total << endl;

    return 0;
}