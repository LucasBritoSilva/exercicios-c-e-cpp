
#include <iostream>
using namespace std;

int insertionSort(int v[], int n) {
    int deslocamentos = 0;

    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
            deslocamentos++;
        }

        v[j + 1] = chave;
    }

    return deslocamentos;
}

int main() {
    int n;

    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    int v[100];

    cout << "Digite os elementos do vetor: ";
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
