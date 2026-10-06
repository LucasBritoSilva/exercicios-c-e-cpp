/*
    Programa que verifica se um determinado número está presente em um vetor.
    A função decide() realiza a busca de forma recursiva, verificando os elementos
    do vetor um por um até encontrar o valor procurado ou chegar ao final do vetor.
    Ao final, o programa informa se o número está ou não presente no vetor.
*/

#include <iostream>
using namespace std;

#define MAX 100

bool decide(int a[], int n, int x) {
    if (n == 0) {
        return false;
    }
    if (a[n - 1] == x) {
        return true;
    }
    return decide(a, n - 1, x);
}

int main() {
    int n, x;
    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> n;
    cout << "Digite o numero que deseja procurar: ";
    cin >> x;
    int a[MAX];
    cout << "Digite os " << n << " elementos do vetor:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << endl;
    if (decide(a, n, x)) {
        cout << "O numero " << x << " esta no vetor." << endl;
    }
    else {
        cout << "O numero " << x << " nao esta no vetor." << endl;
    }
    return 0;
}