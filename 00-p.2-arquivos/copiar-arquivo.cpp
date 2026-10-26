/*
 * Copiar um arquivo de texto
 * ---------------------------------------------------------------------------
 * Objetivo : exemplo de manipulação de arquivos (Exemplo 1 da série): lê
 *            "original.txt" letra por letra (fgetc) e escreve cada letra em
 *            "copia.txt" (fputc). Se copia.txt já existir, será sobrescrito.
 * Preparo  : crie o arquivo original.txt na MESMA pasta de onde o programa
 *            será executado, com qualquer texto dentro. Exemplo no terminal:
 *                echo Ola, mundo! > original.txt
 * Entrada  : nenhuma digitada; o programa lê o arquivo original.txt.
 * Saída    : o arquivo copia.txt e a mensagem "Arquivo copiado!".
 *            Se original.txt não existir, o programa avisa e termina.
 * Compilar : g++ -std=c++11 -Wall -Wextra copiar-arquivo.cpp -o copiar-arquivo
 * Executar : ./copiar-arquivo   (Windows: copiar-arquivo.exe)
 */

#include <cstdio>      // fopen, fclose, fgetc, fputc
#include <iostream>
using namespace std;

int main() {
    FILE* origem;
    FILE* destino;                               // dois "marcadores": um para cada arquivo
    int c;                                       // guarda a letra lida (int por causa do EOF)

    // 1) Abrir o arquivo de origem para LER ("r")
    origem = fopen("original.txt", "r");
    if (origem == nullptr) {                     // nullptr = não conseguiu abrir
        cout << "Nao consegui abrir original.txt." << endl;
        cout << "Crie esse arquivo na pasta atual (ex.: echo Ola, mundo! > original.txt) e execute de novo." << endl;
        return 1;
    }

    // 2) Abrir o arquivo de destino para ESCREVER ("w")
    //    Se copia.txt já existir, o conteúdo antigo é apagado.
    destino = fopen("copia.txt", "w");
    if (destino == nullptr) {
        cout << "Nao consegui criar copia.txt (verifique as permissoes da pasta)." << endl;
        fclose(origem);
        return 1;
    }

    // 3) Copiar: ler uma letra, escrever a letra, repetir até acabar (EOF)
    c = fgetc(origem);                           // pega a primeira letra
    while (c != EOF) {                           // enquanto não acabou o arquivo...
        fputc(c, destino);                       // escreve a letra no destino
        c = fgetc(origem);                       // pega a próxima letra
    }

    // 4) Fechar os dois arquivos
    fclose(origem);
    fclose(destino);

    cout << "Arquivo copiado!" << endl;
    return 0;
}