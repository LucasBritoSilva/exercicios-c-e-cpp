#include <iostream>
using namespace std;
#define MAX 100

float soma(float v[MAX], int n){
    if(n == 1){
        return v[0];
    }
    float s = v[n-1];
    return s + soma(v, n-1);
}

int main(){
    float v[MAX];
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    cout << soma(v,n);
}