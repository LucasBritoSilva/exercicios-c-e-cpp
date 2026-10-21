#include <iostream>
using namespace std;
#define MAX 100

bool busca_binaria(int v[MAX], int n, int x){
   int esq, dir, meio;
   esq = -1;
   dir = n;
   while(esq < dir - 1){
       meio = (esq + dir)/2;
       if (v[meio] < x)
            esq = meio;
        else
            dir = meio;
   }
   if (dir < n && v[dir] == x){
       return true;
   }
   else{
       return false;
   }
}

int main(){
    int v[MAX] = {1, 3, 5, 7, 9, 11, 13};
    int x;
    cin >> x;
    if(busca_binaria(v, 7, x) == true){
        cout << x << " foi encontrado no vetor.";
    }
    else{
        cout << x << " nao foi encontrado no vetor.";
    }
}