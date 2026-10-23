// Uma lanchonete registrou quantos lanches cada um de 6 atendentes vendeu: 
// [4, 3, 1, 5, 6, 7]. Ordene esse vetor em ordem crescente usando o Bubble Sort 
// com flag (parada antecipada).

#include <iostream>
using namespace std;

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n){
    for(int i = 0; i < n; i++){
        bool trocou = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j+1]){
                troca(&a[j], &a[j+1]);
                trocou = true;
            }
        }
        if(!trocou){
            break;
        }
    }
}

int main(){
    int a[] = {4, 3, 1, 5, 6, 7};
    int n = 6;

    bubble_sort(a, n);

    cout << "Vetor ordenado: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}