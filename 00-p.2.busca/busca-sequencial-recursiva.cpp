#include <iostream>
using namespace std;
#define MAX 100

int busca_seqR(int v[MAX], int n, int x, int i) {
    if (i == n) {
        return -1;
    }

    if (v[i] == x) {
        return i;
    }

    return busca_seqR(v, n, x, i + 1);
}

int main(){

}