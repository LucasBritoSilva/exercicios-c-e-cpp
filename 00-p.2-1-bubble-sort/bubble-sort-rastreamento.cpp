#include <iostream>
using namespace std;

int main() {
    int v[] = {3, 5, 1, 4};
    int n = 4;
    int comparacoes = 0;
    int trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j] < v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocas++;
            }
        }
        cout << "Passagem " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << v[k] << " ";
        }
        cout << endl;
    }

    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    return 0;
}