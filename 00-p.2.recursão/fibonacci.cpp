#include <iostream>
using namespace std;

int Fib(int i) {
    if (i == 1 || i == 2) {
        return 1;
    }

    return Fib(i - 1) + Fib(i - 2);
}

int main(){
    int i;
    cin >> i;
    cout << Fib(i);
}