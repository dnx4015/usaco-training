/*
ID: diana.n1
PROG: namenum 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAXN 13


void readDict(char []);

int main(){
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    char num[MAXN];
    scanf("%s", num);
    readDict(num);
    return 0;
}

void readDict(char num[]){
    map<char,char> roseStone;
    roseStone['A'] = roseStone['B'] = roseStone['C'] = '2';
    roseStone['D'] = roseStone['E'] = roseStone['F'] = '3';
    roseStone['G'] = roseStone['H'] = roseStone['I']= '4';
    roseStone['J'] = roseStone['K'] = roseStone['L']= '5';
    roseStone['M'] = roseStone['N'] = roseStone['O']= '6';
    roseStone['P'] = roseStone['R'] = roseStone['S']= '7';
    roseStone['T'] = roseStone['U'] = roseStone['V']= '8';
    roseStone['W'] = roseStone['X'] = roseStone['Y']= '9';

    freopen("dict.txt", "r", stdin);
    char name [MAXN], code [MAXN];
    int l, realL = strlen(num);
    code[realL] = '\0';

    bool found = false;
    while (scanf("%s", name) != EOF){
        l = strlen(name);
        if(l == realL){
            REP(i, realL){
                code[i] = roseStone[name[i]];
            }
            if(strcmp(code, num) == 0){
                found = true;
                printf("%s\n", name);
            }
        }
    }
    if (!found){
        printf("NONE\n");
    }
}
