#include <iostream>
#include <vector>
using namespace std;

void merge(int v[], int inicio, int meio, int fim){
    vector<int> aux(fim - inicio + 1);
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    while(i <= meio && j <= fim){
        if(v[i] > v[j]){
            aux[k] = v[i];
            k++;
            i++;
        }
        else{
            aux[k] = v[j];
            k++;
            j++;
        }
    }
    while(i <= meio){
        aux[k] = v[i];
        i++;
        k++;
    }
    while(j <= fim){
        aux[k] = v[j];
        j++;
        k++;
    }
    for(int a = 0; a < (fim-inicio+1); a++){
        v[inicio+a] = aux[a];
    }
}

void mergeSort(int v[], int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    int meio = (inicio + fim)/2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);
    merge(v, inicio, meio, fim);
}

int main() {
    int v[] = {8, 3, 6, 2, 7, 1, 5, 4};
    mergeSort(v, 0, 7);
    for(int i = 0; i < 8; i++){
        cout << v[i] << " ";
    }
}