// EXEMPLO 2: mesclar dois arquivos, palavra por palavra
// Pega uma palavra de arquivo1.txt, uma de arquivo2.txt, e assim por diante,
// gravando tudo em mesclado.txt.
//
// Exemplo:  arquivo1.txt = "um tres cinco"
//           arquivo2.txt = "dois quatro"
//           mesclado.txt = "um dois tres quatro cinco"
//
// Antes de rodar: crie arquivo1.txt e arquivo2.txt na pasta do programa.

#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 30   // tamanho máximo de cada palavra (incluindo o '\0' final)

int main()
{
    FILE *arq1, *arq2, *saida;
    char palavra1[MAX], palavra2[MAX];   // guardam a palavra lida de cada arquivo
    int ok1, ok2;                        // guardam o resultado do fscanf

    // 1) Abrir os dois arquivos de entrada para LER
    arq1 = fopen("arquivo1.txt", "r");
    arq2 = fopen("arquivo2.txt", "r");
    if (arq1 == nullptr || arq2 == nullptr)
    {
        cout << "Nao consegui abrir os arquivos de entrada\n";
        return 1;
    }

    // 2) Abrir o arquivo de saída para ESCREVER
    saida = fopen("mesclado.txt", "w");
    if (saida == nullptr)
    {
        cout << "Nao consegui abrir mesclado.txt\n";
        return 1;
    }

    // 3) Ler a primeira palavra de cada arquivo
    //    fscanf com "%s" lê UMA palavra (para no espaço ou na quebra de linha).
    //    Se não há mais palavras, ele devolve EOF.
    ok1 = fscanf(arq1, "%29s", palavra1);
    ok2 = fscanf(arq2, "%29s", palavra2);

    // 4) Enquanto OS DOIS ainda têm palavras: grava uma de cada
    while (ok1 != EOF && ok2 != EOF)
    {
        fprintf(saida, "%s %s ", palavra1, palavra2);
        ok1 = fscanf(arq1, "%29s", palavra1);
        ok2 = fscanf(arq2, "%29s", palavra2);
    }

    // 5) Um dos arquivos acabou. Despeja o que sobrou do outro.
    //    (Só um desses dois laços vai realmente executar.)
    while (ok1 != EOF)
    {
        fprintf(saida, "%s ", palavra1);
        ok1 = fscanf(arq1, "%29s", palavra1);
    }
    while (ok2 != EOF)
    {
        fprintf(saida, "%s ", palavra2);
        ok2 = fscanf(arq2, "%29s", palavra2);
    }

    fprintf(saida, "\n");   // quebra de linha no final

    // 6) Fechar tudo
    fclose(arq1);
    fclose(arq2);
    fclose(saida);

    cout << "Arquivo mesclado!\n";
    return 0;
}