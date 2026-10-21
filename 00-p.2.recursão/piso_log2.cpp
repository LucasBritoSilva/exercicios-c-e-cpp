#include <iostream>
using namespace std;

int piso_log2(int n){
    if(n/2 == 0){
        return 0;
    }
    return 1 + piso_log2(n/2);
}

int main(){
    int n;
    cin >> n;
    cout << piso_log2(n);
}