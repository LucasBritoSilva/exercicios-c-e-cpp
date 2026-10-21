#include <iostream>
using namespace std;

int mdc(int x, int n){
    if(n>x){
        int a = n;
        n = x;
        x = a;
    }
    int r = x % n;
    if(r==0){
        return n;
    }
    return mdc(n,r);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << mdc(x,n);
}