/*
 * Bubble Sort com flag — vendas da lanchonete
 * ---------------------------------------------------------------------------
 * Enunciado: uma lanchonete registrou quantos lanches cada um de 6 atendentes
 *            vendeu: [4, 3, 1, 5, 6, 7]. Ordene esse vetor em ordem crescente
 *            usando o Bubble Sort com flag (parada antecipada).
 * Entrada  : nenhuma (o vetor de vendas está fixo no código).
 * Saída    : o vetor de vendas antes e depois da ordenação.
 * Exemplo  : Vendas originais: 4 3 1 5 6 7
 *            Vendas ordenadas: 1 3 4 5 6 7
 * Compilar : g++ -std=c++11 -Wall -Wextra bubble-sort-lanchonete.cpp -o bubble-sort-lanchonete
 * Executar : ./bubble-sort-lanchonete   (Windows: bubble-sort-lanchonete.exe)
 */

#include <iostream>
using namespace std;

// Troca o conteúdo de duas variáveis inteiras (recebe o endereço de cada uma).
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ordena a[0..n-1] em ordem crescente.
// A "flag" trocou indica se houve troca na passagem; se não houve, para antes.
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                troca(&a[j], &a[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) {          // nenhuma troca: já está ordenado
            break;
        }
    }
}

// Mostra os n elementos do vetor em uma linha.
void imprimir(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int vendas[] = {4, 3, 1, 5, 6, 7};   // lanches vendidos por cada atendente
    int n = 6;

    cout << "Vendas originais: ";
    imprimir(vendas, n);

    bubble_sort(vendas, n);

    cout << "Vendas ordenadas: ";
    imprimir(vendas, n);

    return 0;
}