/*
 * Sistema de cadastro de pessoas
 * ---------------------------------------------------------------------------
 * Objetivo : cadastrar pessoas (nome, CPF, renda mensal e idade) e listá-las
 *            com duas situações calculadas: Imposto de Renda (isento até a renda
 *            de 5000, contribuinte acima disso — regra simplificada do exercício)
 *            e aposentadoria (aposentado a partir de 65 anos; antes disso, mostra
 *            quantos anos faltam). Os dados ficam em um vetor de estruturas.
 * Entrada  : um menu (1 = incluir, 2 = listar, 3 = sair). Ao incluir, digite:
 *            nome completo (pode ter espaços), CPF (apenas texto, sem validação —
 *            use dados fictícios), renda mensal (use PONTO nos decimais, ex.:
 *            3500.50) e idade em anos.
 * Saída    : a lista de pessoas cadastradas com IR e aposentadoria.
 * Exemplo  : Incluir: Ana Souza / 000.000.000-00 / 3000 / 65
 *            Listar:  IR: Isento
 *                     Aposentadoria: Aposentado
 * Compilar : g++ -std=c++11 -Wall -Wextra sistema-cadastro.cpp -o sistema-cadastro
 * Executar : ./sistema-cadastro   (Windows: sistema-cadastro.exe)
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_PESSOAS = 100;                 // capacidade do cadastro
const float LIMITE_ISENCAO_IR = 5000.0f;     // renda mensal até este valor: isento (valor didático)
const int IDADE_APOSENTADORIA = 65;          // idade a partir da qual a pessoa é considerada aposentada

struct Pessoa {
    string nome;
    string cpf;
    float renda;
    int idade;
    string ir;                               // "Isento" ou "Contribuinte"
    string aposentadoria;                    // situação em relação à aposentadoria
};

// Informa se a pessoa é isenta ou contribuinte do Imposto de Renda, conforme a renda.
string situacaoIR(float renda) {
    if (renda <= LIMITE_ISENCAO_IR) {
        return "Isento";
    }
    return "Contribuinte";
}

// Informa se a pessoa já é aposentada ou quantos anos faltam para a aposentadoria.
string situacaoAposentadoria(int idade) {
    if (idade < IDADE_APOSENTADORIA) {
        int anos = IDADE_APOSENTADORIA - idade;
        if (anos == 1) {
            return "Falta 1 ano para aposentar";
        }
        return "Faltam " + to_string(anos) + " anos para aposentar";
    }
    return "Aposentado";
}

// Lê os dados de uma pessoa e guarda na posição pos do vetor.
void cadastrarPessoa(Pessoa pessoas[], int pos) {
    cout << "Nome completo: ";
    getline(cin >> ws, pessoas[pos].nome);       // "cin >> ws" descarta o Enter que sobrou da leitura anterior

    cout << "CPF (apenas texto, ex.: 000.000.000-00): ";
    cin >> pessoas[pos].cpf;

    cout << "Renda mensal em reais (use ponto, ex.: 3500.50): ";
    while (!(cin >> pessoas[pos].renda) || pessoas[pos].renda < 0) {
        cin.clear();                             // limpa o estado de erro (ex.: digitou letras)
        cin.ignore(1000, '\n');                  // descarta o restante da linha
        cout << "Valor invalido. Digite uma renda maior ou igual a 0: ";
    }

    cout << "Idade em anos: ";
    while (!(cin >> pessoas[pos].idade) || pessoas[pos].idade < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Valor invalido. Digite uma idade maior ou igual a 0: ";
    }

    pessoas[pos].ir = situacaoIR(pessoas[pos].renda);
    pessoas[pos].aposentadoria = situacaoAposentadoria(pessoas[pos].idade);
}

// Mostra os dados de todas as pessoas cadastradas.
void listarPessoas(const Pessoa pessoas[], int total) {
    if (total == 0) {
        cout << "Nenhuma pessoa cadastrada ainda." << endl;
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << endl;
        cout << "Nome: " << pessoas[i].nome << endl;
        cout << "CPF: " << pessoas[i].cpf << endl;
        cout << "Renda: " << pessoas[i].renda << endl;
        cout << "Idade: " << pessoas[i].idade << endl;
        cout << "IR: " << pessoas[i].ir << endl;
        cout << "Aposentadoria: " << pessoas[i].aposentadoria << endl;
    }
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int totalPessoas = 0;
    int opcao;

    do {
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1 - Incluir pessoa" << endl;
        cout << "2 - Listar pessoas" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao (1 a 3): ";
        while (!(cin >> opcao) || opcao < 1 || opcao > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opcao invalida. Digite 1, 2 ou 3: ";
        }

        if (opcao == 1) {
            if (totalPessoas == MAX_PESSOAS) {
                cout << "O cadastro esta cheio (" << MAX_PESSOAS << " pessoas)." << endl;
            } else {
                cadastrarPessoa(pessoas, totalPessoas);
                totalPessoas++;
                cout << "Pessoa cadastrada!" << endl;
            }
        } else if (opcao == 2) {
            listarPessoas(pessoas, totalPessoas);
        }
    } while (opcao != 3);

    return 0;
}