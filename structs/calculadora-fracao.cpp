/*
 * Calculadora de frações
 * ---------------------------------------------------------------------------
 * Objetivo : realizar uma operação (soma, subtração, multiplicação ou divisão)
 *            entre duas frações. A estrutura "fracao" guarda numerador e
 *            denominador, e cada operação é uma função que devolve uma fração.
 *            O resultado NÃO é simplificado (ex.: 1/2 + 1/2 = 2/2).
 * Entrada  : (nesta ordem)
 *            1) numerador e denominador da 1ª fração (o denominador não pode ser 0);
 *            2) numerador e denominador da 2ª fração (o denominador não pode ser 0);
 *            3) a operação: 1 = somar, 2 = subtrair, 3 = multiplicar, 4 = dividir.
 * Saída    : o resultado no formato numerador/denominador. Na divisão, o programa
 *            avisa quando a 2ª fração vale zero (numerador 0), pois não dá para
 *            dividir por ela.
 * Exemplo  : 1ª fração: numerador 1, denominador 2   (1/2)
 *            2ª fração: numerador 1, denominador 3   (1/3)
 *            Operação : 1 (somar)
 *            Saída    : Resultado: 5/6
 * Compilar : g++ -std=c++11 -Wall -Wextra calculadora-fracao.cpp -o calculadora-fracao
 * Executar : ./calculadora-fracao   (Windows: calculadora-fracao.exe)
 */

#include <iostream>
using namespace std;

// Uma fração: numerador/denominador.
struct fracao {
    int numerador;
    int denominador;
};

// f1 + f2
fracao somar(fracao f1, fracao f2) {
    fracao resultado;

    if (f1.denominador == f2.denominador) {      // mesmo denominador: soma só os numeradores
        resultado.numerador = f1.numerador + f2.numerador;
        resultado.denominador = f2.denominador;
    } else {                                     // denominadores diferentes: multiplica em cruz
        resultado.numerador = f1.numerador * f2.denominador + f1.denominador * f2.numerador;
        resultado.denominador = f1.denominador * f2.denominador;
    }
    return resultado;
}

// f1 - f2
fracao subtrair(fracao f1, fracao f2) {
    fracao resultado;

    if (f1.denominador == f2.denominador) {      // mesmo denominador: subtrai só os numeradores
        resultado.numerador = f1.numerador - f2.numerador;
        resultado.denominador = f2.denominador;
    } else {                                     // denominadores diferentes: multiplica em cruz
        resultado.numerador = f1.numerador * f2.denominador - f1.denominador * f2.numerador;
        resultado.denominador = f1.denominador * f2.denominador;
    }
    return resultado;
}

// f1 * f2
fracao multiplicar(fracao f1, fracao f2) {
    fracao resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// f1 / f2 (multiplica f1 pelo inverso de f2). Pré-condição: f2.numerador != 0.
fracao dividir(fracao f1, fracao f2) {
    fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    return resultado;
}

// Lê uma fração do teclado; repete a pergunta enquanto o denominador for 0.
fracao lerFracao(int numero) {
    fracao f;

    cout << "--- Fracao " << numero << " ---" << endl;
    cout << "Numerador: ";
    cin >> f.numerador;
    cout << "Denominador (diferente de 0): ";
    while (!(cin >> f.denominador) || f.denominador == 0) {
        cin.clear();                             // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                  // descarta o restante da linha
        cout << "O denominador nao pode ser 0. Digite outro numero: ";
    }
    return f;
}

int main() {
    fracao fracao1 = lerFracao(1);
    fracao fracao2 = lerFracao(2);
    int operacao;

    cout << "Escolha a operacao:" << endl;
    cout << "  1 - Somar" << endl;
    cout << "  2 - Subtrair" << endl;
    cout << "  3 - Multiplicar" << endl;
    cout << "  4 - Dividir" << endl;
    cout << "Opcao (1 a 4): ";
    while (!(cin >> operacao) || operacao < 1 || operacao > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Opcao invalida. Digite 1, 2, 3 ou 4: ";
    }

    if (operacao == 4 && fracao2.numerador == 0) {
        cout << "Nao e possivel dividir por uma fracao igual a zero (numerador 0)." << endl;
        return 1;
    }

    fracao resultado;
    if (operacao == 1) {
        resultado = somar(fracao1, fracao2);
    } else if (operacao == 2) {
        resultado = subtrair(fracao1, fracao2);
    } else if (operacao == 3) {
        resultado = multiplicar(fracao1, fracao2);
    } else {
        resultado = dividir(fracao1, fracao2);
    }

    cout << "Resultado: " << resultado.numerador << "/" << resultado.denominador << endl;

    return 0;
}