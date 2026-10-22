// EXEMPLO 3: converter texto para maiúsculas
// Parte 1: grava um texto em "minusculo.txt".
// Parte 2: lê esse arquivo e grava a versão em MAIÚSCULAS em "maiusculo.txt".
//
// Não precisa criar nenhum arquivo antes: o programa cria o minusculo.txt.

#include <iostream>
#include <stdio.h>
#include <ctype.h>      // aqui está o toupper (transforma letra em maiúscula)
using namespace std;

int main()
{
    FILE *minusculo, *maiusculo;
    int c;

    // ---------- PARTE 1: escrever o texto original ----------
    minusculo = fopen("minusculo.txt", "w");   // "w" = escrever
    if (minusculo == nullptr)
    {
        cout << "Erro ao criar minusculo.txt\n";
        return 1;
    }

    // fputs escreve uma string inteira de uma vez
    fputs("Meu primeiro teste com arquivos\n", minusculo);

    fclose(minusculo);   // fecha, para garantir que o texto foi gravado

    // ---------- PARTE 2: ler e converter ----------
    // Precisamos REABRIR o arquivo, agora em modo "r" (ler).
    minusculo = fopen("minusculo.txt", "r");
    maiusculo = fopen("maiusculo.txt", "w");
    if (minusculo == nullptr || maiusculo == nullptr)
    {
        cout << "Erro na abertura\n";
        return 1;
    }

    c = fgetc(minusculo);               // lê a primeira letra
    while (c != EOF)
    {
        fputc(toupper(c), maiusculo);   // converte e escreve
        c = fgetc(minusculo);           // lê a próxima
    }

    fclose(minusculo);
    fclose(maiusculo);

    cout << "Pronto! Veja o arquivo maiusculo.txt\n";
    return 0;
}