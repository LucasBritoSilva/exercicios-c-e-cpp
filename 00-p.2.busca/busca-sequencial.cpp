#include <iostream>
using namespace std;
#define MAX 100

int busca_sequencial(int v[MAX], int n, int x){
    int k;
    for(k = n-1; k >= 0 && v[k] != x; k--);
    return k;
}

int main(){
    int v[MAX] = {4, 8, 15, 16, 23, 42};
    int x;
    cin >> x;
    cout << busca_sequencial(v, 6, x);
}