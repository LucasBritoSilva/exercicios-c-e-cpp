#include <iostream>
using namespace std;

int somaD(int n){
    if(n/10 == 0){
        return n;
    }
    return n%10 + somaD(n/10);
}

int main(){
    int n;
    cin >> n;
    cout << somaD(n);
}