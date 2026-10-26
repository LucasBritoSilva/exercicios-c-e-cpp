/*
 * Converter texto para maiúsculas (linha por linha)
 * ---------------------------------------------------------------------------
 * Objetivo : exemplo de manipulação de arquivos com funções de string: grava uma
 *            frase em "minusculo.txt" com fputs, lê o arquivo linha por linha
 *            com fgets, converte cada linha para MAIÚSCULAS (toupper) e grava o
 *            resultado em "maiusculo.txt". É a versão "por linha" de
 *            converter-maiusculo-arquivo.cpp, que converte letra por letra.
 * Entrada  : nenhuma. O programa cria sozinho o minusculo.txt.
 * Saída    : os arquivos minusculo.txt e maiusculo.txt, criados na pasta de onde
 *            o programa é executado, e uma mensagem de confirmação.
 * Exemplo  : minusculo.txt -> Meu segundo teste com arquivos
 *            maiusculo.txt -> MEU SEGUNDO TESTE COM ARQUIVOS
 * Compilar : g++ -std=c++11 -Wall -Wextra converter-maiusculo-linha.cpp -o converter-maiusculo-linha
 * Executar : ./converter-maiusculo-linha   (Windows: converter-maiusculo-linha.exe)
 */

#include <cctype>      // toupper: transforma uma letra em maiúscula
#include <cstdio>      // fopen, fclose, fgets, fputs
#include <iostream>
using namespace std;

const int TAM_LINHA = 100;   // tamanho máximo de cada trecho lido (incluindo o '\0' final)

// Grava um texto em um arquivo novo. Devolve false se não conseguir gravar.
bool gravarTexto(const char* nomeArquivo, const char* texto) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == nullptr) {
        return false;
    }
    if (fputs(texto, arquivo) == EOF) {          // fputs devolve EOF quando dá erro na gravação
        fclose(arquivo);
        return false;
    }
    fclose(arquivo);                             // fecha para garantir que o texto foi gravado
    return true;
}

// Lê a entrada linha por linha e grava cada linha em MAIÚSCULAS na saída.
void converterParaMaiusculo(FILE* entrada, FILE* saida) {
    char linha[TAM_LINHA];

    while (fgets(linha, sizeof(linha), entrada) != nullptr) {   // lê até TAM_LINHA - 1 caracteres
        for (int i = 0; linha[i] != '\0'; i++) {
            linha[i] = (char) toupper((unsigned char) linha[i]);
        }
        fputs(linha, saida);
    }
}

int main() {
    // PARTE 1: gravar o texto original
    if (!gravarTexto("minusculo.txt", "Meu segundo teste com arquivos\n")) {
        cout << "Erro ao criar minusculo.txt" << endl;
        return 1;
    }

    // PARTE 2: ler o texto, converter e gravar em outro arquivo
    FILE* entrada = fopen("minusculo.txt", "r");
    FILE* saida = fopen("maiusculo.txt", "w");
    if (entrada == nullptr || saida == nullptr) {
        cout << "Erro na abertura dos arquivos" << endl;
        if (entrada != nullptr) {
            fclose(entrada);
        }
        if (saida != nullptr) {
            fclose(saida);
        }
        return 1;
    }

    converterParaMaiusculo(entrada, saida);

    fclose(entrada);
    fclose(saida);

    cout << "Pronto! Veja o arquivo maiusculo.txt" << endl;
    return 0;
}