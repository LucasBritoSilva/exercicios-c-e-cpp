#include <iostream>
using namespace std;

int main() {
    int v[] = {4, 7, 2, 9, 5};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int pos = 0;
        for (int j = 1; j < n - i; j++) {
            if (v[j] > v[pos]) {
                pos = j;
            }
        }
        int ultimo = n - 1 - i;
        int temp = v[pos];
        v[pos] = v[ultimo];
        v[ultimo] = temp;

        cout << "i=" << i << " pos=" << pos << " vetor: ";
        for (int k = 0; k < n; k++) {
            cout << v[k] << " ";
        }
        cout << endl;
    }
    return 0;
}