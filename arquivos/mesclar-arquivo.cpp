/*
 * Mesclar dois arquivos de texto, palavra por palavra
 * ---------------------------------------------------------------------------
 * Objetivo : exemplo de manipulação de arquivos (Exemplo 2 da série): pega uma
 *            palavra de arquivo1.txt, uma de arquivo2.txt, e assim por diante,
 *            gravando tudo em mesclado.txt. Quando um dos arquivos acaba, as
 *            palavras que sobraram do outro são copiadas no final.
 * Preparo  : crie arquivo1.txt e arquivo2.txt na MESMA pasta de onde o programa
 *            será executado. Exemplo no terminal:
 *                echo um tres cinco > arquivo1.txt
 *                echo dois quatro > arquivo2.txt
 * Entrada  : nenhuma digitada; o programa lê os dois arquivos.
 * Saída    : o arquivo mesclado.txt (palavras separadas por espaço) e a
 *            mensagem "Arquivo mesclado!".
 * Exemplo  : arquivo1.txt = "um tres cinco"
 *            arquivo2.txt = "dois quatro"
 *            mesclado.txt = "um dois tres quatro cinco"
 * Compilar : g++ -std=c++11 -Wall -Wextra mesclar-arquivo.cpp -o mesclar-arquivo
 * Executar : ./mesclar-arquivo   (Windows: mesclar-arquivo.exe)
 */

#include <cstdio>      // fopen, fclose, fscanf, fprintf
#include <iostream>
using namespace std;

const int TAM_PALAVRA = 30;   // tamanho máximo de cada palavra (incluindo o '\0' final)

int main() {
    FILE* arq1;
    FILE* arq2;
    FILE* saida;
    char palavra1[TAM_PALAVRA];                  // guardam a palavra lida de cada arquivo
    char palavra2[TAM_PALAVRA];
    int ok1, ok2;                                // guardam o resultado do fscanf

    // 1) Abrir os dois arquivos de entrada para LER
    arq1 = fopen("arquivo1.txt", "r");
    arq2 = fopen("arquivo2.txt", "r");
    if (arq1 == nullptr || arq2 == nullptr) {
        cout << "Nao consegui abrir arquivo1.txt e/ou arquivo2.txt." << endl;
        cout << "Crie os dois na pasta atual (ex.: echo um tres cinco > arquivo1.txt) e execute de novo." << endl;
        if (arq1 != nullptr) {
            fclose(arq1);
        }
        if (arq2 != nullptr) {
            fclose(arq2);
        }
        return 1;
    }

    // 2) Abrir o arquivo de saída para ESCREVER
    saida = fopen("mesclado.txt", "w");
    if (saida == nullptr) {
        cout << "Nao consegui criar mesclado.txt (verifique as permissoes da pasta)." << endl;
        fclose(arq1);
        fclose(arq2);
        return 1;
    }

    // 3) Ler a primeira palavra de cada arquivo
    //    fscanf com "%29s" lê UMA palavra de até 29 letras (para no espaço ou na
    //    quebra de linha). Se não há mais palavras, ele devolve EOF.
    ok1 = fscanf(arq1, "%29s", palavra1);
    ok2 = fscanf(arq2, "%29s", palavra2);

    // 4) Enquanto OS DOIS ainda têm palavras: grava uma de cada
    while (ok1 != EOF && ok2 != EOF) {
        fprintf(saida, "%s %s ", palavra1, palavra2);
        ok1 = fscanf(arq1, "%29s", palavra1);
        ok2 = fscanf(arq2, "%29s", palavra2);
    }

    // 5) Um dos arquivos acabou. Despeja o que sobrou do outro.
    //    (Só um desses dois laços vai realmente executar.)
    while (ok1 != EOF) {
        fprintf(saida, "%s ", palavra1);
        ok1 = fscanf(arq1, "%29s", palavra1);
    }
    while (ok2 != EOF) {
        fprintf(saida, "%s ", palavra2);
        ok2 = fscanf(arq2, "%29s", palavra2);
    }

    fprintf(saida, "\n");                        // quebra de linha no final

    // 6) Fechar tudo
    fclose(arq1);
    fclose(arq2);
    fclose(saida);

    cout << "Arquivo mesclado!" << endl;
    return 0;
}