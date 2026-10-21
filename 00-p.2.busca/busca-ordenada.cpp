#include <iostream>
using namespace std;
#define MAX 100

int busca_ordenada(int v[MAX], int n, int x){
    int k;
    for(k = 0; k < n && v[k] < x; k++);
    return k;
}

int main(){
    int v[MAX] = {10, 20, 20, 30, 40};
    int x;
    cin >> x;
    cout << busca_ordenada(v, 5, x);
}