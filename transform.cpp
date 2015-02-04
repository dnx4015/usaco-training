/*
ID: diana.n1
PROG: transform
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAXN 10
#define N_TYPES 8

enum TYPES {ROT90, ROT180, ROT270, REFLECT, \
            R_ROT90, R_ROT180, R_ROT270, SAME};
#define COMBINATION 5
#define ORIGINAL 6
#define INVALID 7

char pattern[MAXN][MAXN];
char transformed[MAXN][MAXN];

int getTransform(int n);
bool doCompare(int n, int type);
char getChar(int i, int j, int n, int type);

int main(){
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n, result;
    scanf("%d",&n);
    
    REP(i,n) scanf("%s", &pattern[i][0]);
    REP(i,n) scanf("%s", &transformed[i][0]);
    
    result = getTransform(n);
    printf("%d\n", result);
    return 0;
}

int getTransform(int n){
    REP(type, N_TYPES){
        if ( doCompare(n, type) ) {
            if (type < 4) return type + 1;
            if (type < 7) return COMBINATION;
            return ORIGINAL;
        }
    }
    return INVALID;
}

bool doCompare(int n, int type){
    REP(i, n)
        REP(j, n)
            if ( getChar(i, j, n, type) != transformed[i][j] )
                return false;
    return true;
}

char getChar(int i, int j, int n, int type){
    switch ( type ) {
        case ROT90: return pattern[n-j-1][i];
        case ROT180: return pattern[n-i-1][n-j-1];
        case ROT270: return pattern[j][n-i-1];
        case REFLECT: return pattern[i][n-j-1];
        case R_ROT90: return pattern[n-j-1][n-i-1];
        case R_ROT180: return pattern[n-i-1][j];
        case R_ROT270: return pattern[j][i];
        case SAME: return pattern[i][j]; 
    }
}
