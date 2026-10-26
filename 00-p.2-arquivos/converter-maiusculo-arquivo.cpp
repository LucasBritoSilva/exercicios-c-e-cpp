/*
 * Converter texto para maiúsculas (letra por letra)
 * ---------------------------------------------------------------------------
 * Objetivo : exemplo de manipulação de arquivos de texto (Exemplo 3 da série,
 *            junto com copiar-arquivo.cpp e mesclar-arquivo.cpp), em duas partes:
 *            Parte 1 grava um texto em "minusculo.txt";
 *            Parte 2 lê esse arquivo letra por letra (fgetc) e grava a versão
 *            em MAIÚSCULAS em "maiusculo.txt" (toupper + fputc).
 * Entrada  : nenhuma. O programa cria sozinho o minusculo.txt.
 * Saída    : os arquivos minusculo.txt e maiusculo.txt, criados na pasta de onde
 *            o programa é executado, e uma mensagem de confirmação.
 * Exemplo  : minusculo.txt -> Meu primeiro teste com arquivos
 *            maiusculo.txt -> MEU PRIMEIRO TESTE COM ARQUIVOS
 * Compilar : g++ -std=c++11 -Wall -Wextra converter-maiusculo-arquivo.cpp -o converter-maiusculo-arquivo
 * Executar : ./converter-maiusculo-arquivo   (Windows: converter-maiusculo-arquivo.exe)
 */

#include <cctype>      // toupper: transforma uma letra em maiúscula
#include <cstdio>      // fopen, fclose, fgetc, fputc, fputs
#include <iostream>
using namespace std;

int main() {
    FILE* minusculo;
    FILE* maiusculo;
    int c;                                       // guarda a letra lida (int por causa do EOF)

    // ---------- PARTE 1: escrever o texto original ----------
    minusculo = fopen("minusculo.txt", "w");     // "w" = escrever (cria o arquivo ou apaga o conteúdo antigo)
    if (minusculo == nullptr) {                  // nullptr = não conseguiu abrir
        cout << "Erro ao criar minusculo.txt" << endl;
        return 1;
    }

    fputs("Meu primeiro teste com arquivos\n", minusculo);   // fputs escreve uma string inteira de uma vez
    fclose(minusculo);                           // fecha para garantir que o texto foi gravado

    // ---------- PARTE 2: ler e converter ----------
    // Precisamos REABRIR o arquivo, agora em modo "r" (ler).
    minusculo = fopen("minusculo.txt", "r");
    maiusculo = fopen("maiusculo.txt", "w");
    if (minusculo == nullptr || maiusculo == nullptr) {
        cout << "Erro na abertura dos arquivos" << endl;
        if (minusculo != nullptr) {
            fclose(minusculo);
        }
        if (maiusculo != nullptr) {
            fclose(maiusculo);
        }
        return 1;
    }

    c = fgetc(minusculo);                        // lê a primeira letra
    while (c != EOF) {                           // repete até o fim do arquivo (EOF)
        fputc(toupper(c), maiusculo);            // converte e escreve
        c = fgetc(minusculo);                    // lê a próxima
    }

    fclose(minusculo);
    fclose(maiusculo);

    cout << "Pronto! Veja o arquivo maiusculo.txt" << endl;
    return 0;
}