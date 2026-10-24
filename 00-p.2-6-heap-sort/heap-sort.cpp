#include <iostream>
using namespace std;

// Troca os elementos das posições a e b
void trocar(int v[], int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

// Faz o elemento da posição i "descer" no heap de tamanho tam,
// até a propriedade de heap máximo voltar a valer.
void peneirar(int v[], int tam, int i) {
    while (true) {
        int esq = 2 * i + 1;                      // filho esquerdo
        int dir = 2 * i + 2;                      // filho direito
        int maior = i;                            // supomos que o maior é o próprio pai

        if (esq < tam && v[esq] > v[maior]) {     // filho esquerdo existe e é maior?
            maior = esq;
        }
        if (dir < tam && v[dir] > v[maior]) {     // filho direito existe e é maior?
            maior = dir;
        }

        if (maior == i) {                         // pai já é maior que os filhos: terminou
            break;
        }

        trocar(v, i, maior);                      // o pai desce uma posição
        i = maior;                                // continua a partir da nova posição
    }
}

// Ordena v[0..n-1] em ordem crescente (Heap Sort)
void heapSort(int v[], int n) {
    // Fase 1: construir o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        peneirar(v, n, i);
    }

    // Fase 2: remover o maior repetidamente
    for (int fim = n - 1; fim > 0; fim--) {
        trocar(v, 0, fim);                        // o maior do heap vai para a posição final
        peneirar(v, fim, 0);                      // o heap agora tem 'fim' elementos
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

    heapSort(v, n);

    cout << "Depois: ";
    imprimir(v, n);

    return 0;
}