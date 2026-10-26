/*
 * Inserção e remoção de elementos em um vetor (iterativa e recursiva)
 * ---------------------------------------------------------------------------
 * Objetivo : inserir e remover elementos em uma posição qualquer de um vetor,
 *            deslocando os demais elementos. Cada operação existe em duas
 *            versões: com laço (remover, inserir) e recursiva (remover_recursivo,
 *            inserir_recursivo). Todas devolvem o NOVO tamanho do vetor.
 * Entrada  : 1) a quantidade inicial de elementos (de 1 a 100);
 *            2) os elementos iniciais, separados por espaço ou Enter;
 *            3) em seguida, uma opção do menu (0 a 5) e os dados que ela pedir
 *               (posição e, na inserção, o valor). As posições começam em 0.
 * Saída    : o vetor atualizado após cada operação.
 * Exemplo  : Entrada:  5
 *                      10 20 30 40 50
 *                      3        (opcao do menu: inserir recursivo)
 *                      2        (posicao)
 *                      99       (valor)
 *            Saída:    Elemento inserido usando recursao!
 *                      Vetor: 10 20 99 30 40 50
 * Compilar : g++ -std=c++11 -Wall -Wextra remove-e-insere.cpp -o remove-e-insere
 * Executar : ./remove-e-insere   (Windows: remove-e-insere.exe)
 */

#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 100;   // capacidade máxima do vetor

// Remove o elemento da posição k, deslocando os seguintes uma casa para a
// esquerda (versão com laço). Devolve o novo tamanho do vetor.
int remover(int n, int v[], int k) {
    for (; k < n - 1; k++) {
        v[k] = v[k + 1];
    }
    return n - 1;
}

// Mesma operação de remover(), em versão recursiva.
int remover_recursivo(int n, int v[], int k) {
    if (k >= n - 1) {                   // chegou ao último elemento: nada mais a deslocar
        return n - 1;
    }
    v[k] = v[k + 1];                    // traz o próximo elemento para a posição k
    return remover_recursivo(n, v, k + 1);
}

// Insere o valor y na posição k, deslocando os elementos de k em diante uma
// casa para a direita (versão com laço). Devolve o novo tamanho do vetor.
int inserir(int n, int v[], int k, int y) {
    for (int i = n; i > k; i--) {
        v[i] = v[i - 1];
    }
    v[k] = y;
    return n + 1;
}

// Mesma operação de inserir(), em versão recursiva.
// A cada chamada, um elemento é empurrado para a direita e n diminui até chegar a k.
int inserir_recursivo(int n, int v[], int k, int x) {
    if (n == k) {                       // chegou à posição de inserção
        v[k] = x;
        return n + 1;
    }
    v[n] = v[n - 1];                    // desloca o elemento anterior uma casa para a direita
    return 1 + inserir_recursivo(n - 1, v, k, x);   // cada nível soma 1: no fim, o total é o tamanho original + 1
}

// Mostra os n elementos do vetor em uma linha.
void mostrarVetor(const int v[], int n) {
    cout << "Vetor: ";
    if (n == 0) {
        cout << "(vazio)";
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Pergunta até o usuário digitar um inteiro entre minimo e maximo (inclusive).
int lerInteiro(const char* descricao, int minimo, int maximo) {
    int valor;
    cout << descricao << " (" << minimo << " a " << maximo << "): ";
    while (!(cin >> valor) || valor < minimo || valor > maximo) {
        cin.clear();                    // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');         // descarta o restante da linha
        cout << "Valor invalido. Digite um numero de " << minimo << " a " << maximo << ": ";
    }
    return valor;
}

int main() {
    int v[MAX_ELEMENTOS];
    int n = lerInteiro("Quantos elementos tem o vetor inicial", 1, MAX_ELEMENTOS);

    cout << "Digite os " << n << " elementos do vetor (separados por espaco ou Enter): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Lembrete: as posicoes comecam em 0 (o 1o elemento esta na posicao 0)." << endl;

    int opcao;
    do {
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Remover elemento" << endl;
        cout << "3 - Inserir elemento (recursivo)" << endl;
        cout << "4 - Remover elemento (recursivo)" << endl;
        cout << "5 - Mostrar vetor" << endl;
        cout << "0 - Sair" << endl;
        opcao = lerInteiro("Escolha uma opcao", 0, 5);

        if (opcao == 1 || opcao == 3) {                 // inserir
            if (n == MAX_ELEMENTOS) {
                cout << "O vetor esta cheio (" << MAX_ELEMENTOS << " elementos): nao e possivel inserir." << endl;
            } else {
                int posicao = lerInteiro("Posicao onde deseja inserir", 0, n);
                int valor;
                cout << "Digite o valor a inserir: ";
                cin >> valor;

                if (opcao == 1) {
                    n = inserir(n, v, posicao, valor);
                    cout << "Elemento inserido!" << endl;
                } else {
                    n = inserir_recursivo(n, v, posicao, valor);
                    cout << "Elemento inserido usando recursao!" << endl;
                }
                mostrarVetor(v, n);
            }
        } else if (opcao == 2 || opcao == 4) {          // remover
            if (n == 0) {
                cout << "O vetor esta vazio: nao ha elemento para remover." << endl;
            } else {
                int posicao = lerInteiro("Posicao do elemento que deseja remover", 0, n - 1);

                if (opcao == 2) {
                    n = remover(n, v, posicao);
                    cout << "Elemento removido!" << endl;
                } else {
                    n = remover_recursivo(n, v, posicao);
                    cout << "Elemento removido usando recursao!" << endl;
                }
                mostrarVetor(v, n);
            }
        } else if (opcao == 5) {
            mostrarVetor(v, n);
        }
    } while (opcao != 0);

    cout << "Programa encerrado." << endl;

    return 0;
}