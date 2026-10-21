#include <iostream>
using namespace std;

int pot(int x, int n){
    if(n==0){
        return 1;
    }
    int som = 1;
    for(int i=0; i < n; i++){
        som *= x;
    }
    return som;
}

int potR(int x, int n){
    if(n==0){
        return 1;
    }
    return x * potR(x, n-1);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << pot(x,n) << endl;
    cout << potR(x,n);
}