/*
 * Ordenação e busca binária em um vetor
 * ---------------------------------------------------------------------------
 * Objetivo : ler um vetor, ordená-lo com o algoritmo escolhido (Bubble,
 *            Selection ou Insertion Sort) e depois procurar um número com
 *            busca binária. Se o vetor já estiver ordenado, a ordenação é
 *            dispensada.
 * Entrada  : 1) o algoritmo: 1 = Bubble, 2 = Selection, 3 = Insertion;
 *            2) a quantidade n de números (de 1 a 100);
 *            3) os n números inteiros, separados por espaço ou Enter;
 *            4) o número que deseja procurar.
 * Saída    : o vetor lido, o vetor ordenado e a posição do número procurado
 *            (a contagem de posições começa em 0) ou aviso de que não existe.
 * Exemplo  : Entrada:  1
 *                      5
 *                      5 3 1 8 2
 *                      8
 *            Saída:    Vetor ordenado: 1 2 3 5 8
 *                      Numero 8 encontrado na posicao 4 (a contagem comeca em 0).
 * Compilar : g++ -std=c++11 -Wall -Wextra ordenacao-e-busca.cpp -o ordenacao-e-busca
 * Executar : ./ordenacao-e-busca   (Windows: ordenacao-e-busca.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Troca o conteúdo de duas variáveis inteiras (recebe o endereço de cada uma).
void troca(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// Devolve true se o vetor já está em ordem crescente.
bool esta_ordenado(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] < v[i]) {
            return false;
        }
    }
    return true;
}

// Bubble Sort: troca vizinhos fora de ordem; o maior "sobe" até o fim a cada passagem.
void ordenar_bubble(int v[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}

// Selection Sort: seleciona o menor da parte não ordenada e o coloca na posição i.
void ordenar_selection(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        troca(&v[i], &v[menor]);
    }
}

// Insertion Sort: insere cada elemento (x) na posição certa da parte já ordenada.
void ordenar_insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = x;
    }
}

// Busca binária em vetor ordenado. Devolve a posição de x ou -1 se x não existir.
int busca_binaria(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == x) {
            return meio;                // achou
        } else if (x < v[meio]) {
            fim = meio - 1;             // continua na metade esquerda
        } else {
            inicio = meio + 1;          // continua na metade direita
        }
    }

    return -1;                          // não encontrou
}

// Mostra os n elementos do vetor em uma linha.
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int algoritmo, n, x;
    int v[MAX_ELEMENTOS];

    cout << "Escolha o algoritmo de ordenacao:" << endl;
    cout << "  1 - Bubble Sort" << endl;
    cout << "  2 - Selection Sort" << endl;
    cout << "  3 - Insertion Sort" << endl;
    cout << "Opcao (1 a 3): ";
    while (!(cin >> algoritmo) || algoritmo < 1 || algoritmo > 3) {
        cin.clear();                                // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                     // descarta o restante da linha
        cout << "Opcao invalida. Digite 1, 2 ou 3: ";
    }

    cout << "Quantos numeros tem o vetor (1 a " << MAX_ELEMENTOS << ")? ";
    while (!(cin >> n) || n < 1 || n > MAX_ELEMENTOS) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Valor invalido. Digite uma quantidade de 1 a " << MAX_ELEMENTOS << ": ";
    }

    cout << "Digite os " << n << " numeros inteiros (separados por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Vetor lido: ";
    imprimir(v, n);

    if (esta_ordenado(v, n)) {
        cout << "O vetor ja estava ordenado; nenhuma ordenacao foi necessaria." << endl;
    } else if (algoritmo == 1) {
        ordenar_bubble(v, n);
    } else if (algoritmo == 2) {
        ordenar_selection(v, n);
    } else {
        ordenar_insertion(v, n);
    }

    cout << "Vetor ordenado: ";
    imprimir(v, n);

    cout << "Digite o numero que deseja buscar: ";
    cin >> x;

    int posicao = busca_binaria(v, n, x);

    if (posicao >= 0) {
        cout << "Numero " << x << " encontrado na posicao " << posicao
             << " (a contagem comeca em 0)." << endl;
    } else {
        cout << "Numero " << x << " nao encontrado no vetor." << endl;
    }

    return 0;
}