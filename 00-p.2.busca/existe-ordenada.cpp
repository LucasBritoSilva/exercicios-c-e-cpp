#include <iostream>
using namespace std;
#define MAX 100

int existe(int n, int v[MAX], int x){
    int esq, dir, meio;
    esq = -1;
    dir = n;
    while(esq < dir -1){
        meio = (esq + dir)/2;
        if(v[meio] < x){
            esq = meio;
        }
        else{
            dir = meio;
        }
    }
    if(dir < n && v[dir] == x){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
}