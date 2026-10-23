
#include <iostream>
using namespace std;
#define MAX 100

int bubbleSort(int v[], int n){
    int trocas = 0;

    for(int i = 0; i < n - 1; i++){
        bool troca = false;

        for(int j = 0; j < n - 1 - i; j++){
            if(v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;

                troca = true;
                trocas++;
            }
        }

        if(!troca){
            break;
        }
    }

    return trocas;
}

int main(){
    int n, v[MAX];

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int totalTrocas = bubbleSort(v, n);

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    cout << endl << "Trocas: " << totalTrocas << endl;

    return 0;
}