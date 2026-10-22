// EXEMPLO 1: copiar um arquivo
// Lê "original.txt" letra por letra e escreve cada letra em "copia.txt".
//
// Antes de rodar: crie um arquivo chamado original.txt na mesma pasta
// do programa, com qualquer texto dentro.

#include <iostream>
#include <stdio.h>      // aqui estão fopen, fclose, fgetc, fputc...
using namespace std;

int main()
{
    FILE *origem, *destino;   // dois "marcadores": um para cada arquivo
    int c;                    // guarda a letra lida (int por causa do EOF)

    // 1) Abrir o arquivo de origem para LER ("r")
    origem = fopen("original.txt", "r");
    if (origem == nullptr)    // nullptr = não conseguiu abrir
    {
        cout << "Nao consegui abrir original.txt\n";
        return 1;
    }

    // 2) Abrir o arquivo de destino para ESCREVER ("w")
    //    Se copia.txt já existir, o conteúdo antigo é apagado.
    destino = fopen("copia.txt", "w");
    if (destino == nullptr)
    {
        cout << "Nao consegui abrir copia.txt\n";
        fclose(origem);
        return 1;
    }

    // 3) Copiar: ler uma letra, escrever a letra, repetir até acabar (EOF)
    c = fgetc(origem);            // pega a primeira letra
    while (c != EOF)              // enquanto não acabou o arquivo...
    {
        fputc(c, destino);        // escreve a letra no destino
        c = fgetc(origem);        // pega a próxima letra
    }

    // 4) Fechar os dois arquivos
    fclose(origem);
    fclose(destino);

    cout << "Arquivo copiado!\n";
    return 0;
}