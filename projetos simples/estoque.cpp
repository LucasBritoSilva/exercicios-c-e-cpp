/*
 * Controle de estoque de produtos
 * ---------------------------------------------------------------------------
 * Objetivo : cadastrar 3 produtos (nome, preço e quantidade), listá-los,
 *            calcular o valor total em estoque, buscar um produto pelo nome e
 *            reajustar o preço de um produto por um percentual. Usa a estrutura
 *            "Produto" e funções que recebem o vetor de produtos por ponteiro.
 * Entrada  : (nesta ordem)
 *            1) para cada um dos 3 produtos: nome (pode ter espaços), preço
 *               (use PONTO como separador decimal, ex.: 5.50) e quantidade;
 *            2) o nome do produto que deseja buscar;
 *            3) o índice (0, 1 ou 2) do produto que terá o preço reajustado;
 *            4) o percentual de aumento (ex.: 10 para +10%).
 * Saída    : a lista de produtos, o valor total em estoque, o resultado da busca
 *            e o estoque atualizado.
 * Exemplo  : Produtos digitados (um dado por linha):
 *               Arroz Integral / 5.50 / 10
 *               Feijao / 7 / 4
 *               Oleo / 6.25 / 3
 *            Busca: Feijao | Índice: 1 | Percentual: 10
 *            Saída (resumo): Valor total em estoque: R$ 101.75
 *                            Novo preco de Feijao: R$ 7.70
 * Compilar : g++ -std=c++11 -Wall -Wextra estoque.cpp -o estoque
 * Executar : ./estoque   (Windows: estoque.exe)
 */

#include <iomanip>     // fixed e setprecision: preços com 2 casas decimais
#include <iostream>
#include <string>
using namespace std;

const int QTD_PRODUTOS = 3;   // quantidade de produtos cadastrados

struct Produto {
    string nome;
    float preco;
    int quantidade;
};

// Lê do teclado os dados de 'tamanho' produtos e guarda no vetor estoque.
void cadastrarProdutos(Produto* estoque, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "--- Produto " << i + 1 << " de " << tamanho << " ---" << endl;
        cout << "Nome (pode ter espacos): ";
        getline(cin >> ws, estoque[i].nome);     // "cin >> ws" descarta o Enter que sobrou da leitura anterior
        cout << "Preco em reais (use ponto, ex.: 5.50): ";
        cin >> estoque[i].preco;
        cout << "Quantidade em estoque: ";
        cin >> estoque[i].quantidade;
    }
}

// Mostra todos os produtos, cada um com seu índice.
void listarProdutos(const Produto* estoque, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "[" << i << "] " << estoque[i].nome
             << " | Preco: R$ " << estoque[i].preco
             << " | Quantidade: " << estoque[i].quantidade << endl;
    }
}

// Soma preço x quantidade de todos os produtos.
float valorTotalEstoque(const Produto* estoque, int tamanho) {
    float total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += estoque[i].preco * estoque[i].quantidade;
    }
    return total;
}

// Procura um produto pelo nome e mostra o resultado. Devolve o índice do produto
// ou -1 se ele não for encontrado.
int buscarProdutoPorNome(const Produto* estoque, int tamanho, const string& nome) {
    for (int i = 0; i < tamanho; i++) {
        if (nome == estoque[i].nome) {
            cout << "Produto encontrado: [" << i << "] " << estoque[i].nome
                 << " | Preco: R$ " << estoque[i].preco
                 << " | Quantidade: " << estoque[i].quantidade << endl;
            return i;
        }
    }
    cout << "Produto nao encontrado." << endl;
    return -1;
}

// Aumenta o preço do produto na posição 'indice' em 'percentual' por cento.
void aumentarPreco(Produto* estoque, int indice, float percentual) {
    estoque[indice].preco *= (1 + (percentual / 100));
}

int main() {
    Produto estoque[QTD_PRODUTOS];

    cout << fixed << setprecision(2);            // números decimais sempre com 2 casas

    cadastrarProdutos(estoque, QTD_PRODUTOS);

    cout << endl << "=== Produtos cadastrados ===" << endl;
    listarProdutos(estoque, QTD_PRODUTOS);
    cout << "Valor total em estoque: R$ " << valorTotalEstoque(estoque, QTD_PRODUTOS) << endl;

    string nome;
    cout << endl << "Digite o nome do produto que deseja buscar: ";
    getline(cin >> ws, nome);
    buscarProdutoPorNome(estoque, QTD_PRODUTOS, nome);

    int indice;
    float percentual;
    cout << endl << "Digite o indice do produto (0 a " << QTD_PRODUTOS - 1 << ") para reajustar o preco: ";
    while (!(cin >> indice) || indice < 0 || indice >= QTD_PRODUTOS) {
        cin.clear();                             // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                  // descarta o restante da linha
        cout << "Indice invalido. Digite um valor de 0 a " << QTD_PRODUTOS - 1 << ": ";
    }
    cout << "Digite o percentual de aumento (ex.: 10 para +10%): ";
    cin >> percentual;

    aumentarPreco(estoque, indice, percentual);
    cout << "Novo preco de " << estoque[indice].nome << ": R$ " << estoque[indice].preco << endl;

    cout << endl << "=== Estoque atualizado ===" << endl;
    listarProdutos(estoque, QTD_PRODUTOS);

    return 0;
}