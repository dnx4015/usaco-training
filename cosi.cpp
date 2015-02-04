/*
ID: diana.n1
PROG: ariprog 
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 250*250*4 + 2
bool bi[MAX];
int n , m, x[MAX];
int a;
inline bool dfs( int x, int d){
    if ( !bi[x] ) return false;
    if ( d == 0 ) return true;
    return dfs( x + a, d - 1); 
}

int main(){
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    scanf("%d %d",&n,&m);
    int k = 0;
    for( int i = 0; i <= m; i++){
        for( int j = i; j <= m; j++){
            int y = i*i + j*j;
            if ( !bi[y] ) x[k++] = y;
            bi[y] = 1;
        }
    }
    sort( x , x + k );
    bool cagao = true;
    for( a = 1; a <= 2*m*m/(n-1); a++){
        for( int i = 0; i < k ; i++){
            if (dfs( x[i], n - 1) ) {
                printf("%d %d\n", x[i], a );
                cagao = false;
            }
        }
    }
    if (cagao) puts("NONE");
    return 0;
}
