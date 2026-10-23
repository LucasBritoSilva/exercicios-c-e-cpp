#include <iostream>
using namespace std;

// Ordena o vetor v de tamanho n em ordem crescente (Selection Sort)
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {            // i = primeira posição da parte não ordenada
        int indiceMenor = i;                      // supomos que o menor está em i

        for (int j = i + 1; j < n; j++) {         // procura o menor no resto do vetor
            if (v[j] < v[indiceMenor]) {          // achou um valor menor que o menor atual?
                indiceMenor = j;                  // guarda a posição dele
            }
        }

        if (indiceMenor != i) {                   // só troca se o menor não estiver já no lugar
            int temp = v[i];
            v[i] = v[indiceMenor];
            v[indiceMenor] = temp;
        }
    }
}

// Imprime os elementos do vetor
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int v[] = {5, 2, 8, 1, 4};
    int n = 5;

    cout << "Antes:  ";
    imprimir(v, n);

    selectionSort(v, n);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}