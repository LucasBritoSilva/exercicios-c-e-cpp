/*
 * Existe? — verificação recursiva
 * ---------------------------------------------------------------------------
 * Objetivo : verificar se um número x está presente em um vetor, de forma
 *            recursiva: examina o último elemento e, se não for x, repete a
 *            verificação para os n-1 primeiros. Não exige vetor ordenado.
 * Entrada  : 1) a quantidade n de elementos (de 1 a 100);
 *            2) o número x que deseja procurar;
 *            3) os n elementos do vetor (o programa pede um por vez).
 * Saída    : informa se x está ou não no vetor.
 * Exemplo  : Entrada:  5        (quantidade)
 *                      3        (numero procurado)
 *                      1, 2, 3, 4, 5   (um elemento por vez)
 *            Saída:    O numero 3 esta no vetor.
 * Compilar : g++ -std=c++11 -Wall -Wextra existe-recursivo.cpp -o existe-recursivo
 * Executar : ./existe-recursivo   (Windows: existe-recursivo.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Devolve true se x aparece em a[0..n-1].
bool existe_recursivo(int a[], int n, int x) {
    if (n == 0) {                       // vetor vazio: x não está
        return false;
    }
    if (a[n - 1] == x) {                // o último elemento é x
        return true;
    }
    return existe_recursivo(a, n - 1, x);   // procura nos n-1 primeiros
}

int main() {
    int n, x;
    int a[MAX_ELEMENTOS];

    cout << "Digite a quantidade de elementos do vetor (1 a " << MAX_ELEMENTOS << "): ";
    while (!(cin >> n) || n < 1 || n > MAX_ELEMENTOS) {
        cin.clear();                                // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                     // descarta o restante da linha
        cout << "Valor invalido. Digite uma quantidade de 1 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite o numero que deseja procurar: ";
    cin >> x;

    cout << "Digite os " << n << " elementos do vetor:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << endl;
    if (existe_recursivo(a, n, x)) {
        cout << "O numero " << x << " esta no vetor." << endl;
    } else {
        cout << "O numero " << x << " nao esta no vetor." << endl;
    }

    return 0;
}