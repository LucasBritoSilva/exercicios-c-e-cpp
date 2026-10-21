#include <iostream>
using namespace std;

int ciclo(int n){
    int comp = 1;
    while(n != 1){
        if(n%2 == 0){
            n = n/2;
        }
        else{
            n = n*3 + 1;
        }
        comp++;
    }
    return comp;
}

int main(){
    int n;
    cin >> n;
    cout << ciclo(n);
}
