#include <iostream>
using namespace std;

int main() {
    int v[] = {3, 8, 5, 9, 1};
    int n = 5;
    int deslocamentos = 0;

    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < chave) {
            v[j + 1] = v[j];
            j--;
            deslocamentos++;
        }
        v[j + 1] = chave;

        cout << "i=" << i << " chave=" << chave << " j=" << j << " vetor: ";
        for (int k = 0; k < n; k++) {
            cout << v[k] << " ";
        }
        cout << endl;
    }

    cout << "Deslocamentos: " << deslocamentos << endl;
    return 0;
}