#include <iostream>
using namespace std;

int potencia(int x, int n){
    if(n==0){
        return 1;
    }
    else if(n%2 == 0){
        int p = potencia(x,n/2);
        return p * p;
    }
    else{
        return x * potencia(x,n-1);
    }
}

int main(){
    int x,n;
    cin >> x >> n;
    cout << potencia(x,n);
}