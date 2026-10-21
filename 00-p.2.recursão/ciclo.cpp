#include <iostream>
using namespace std;

int ciclo(int n){
    int comp = 1;
    cout << n;
    while(n != 1){
        if(n%2 == 0){
            n = n/2;
        }
        else{
            n = n*3 + 1;
        }
        cout << " " << n;
        comp++;
    }
    cout << endl;
    return comp;
}

int cicloR(int n){
    cout << n << " ";
    if(n == 1){
        cout << endl;
        return 1;
    }
    else if(n%2 == 0){
        return 1 + cicloR(n/2);
    }
    else{
        return 1 + cicloR(n*3 + 1);
    }
}

int main(){
    int n;
    cin >> n;
    cout << ciclo(n) << endl;
    cout << cicloR(n);
}