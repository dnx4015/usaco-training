/*
ID: diana.n1
PROG: palsquare 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MAXN 300
#define MAX_DIGITS 20

char* toBase(int, int);
bool isPalindrome(char[]);
char* flip(char[]);
char map[20];

int main(){
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int b;
    scanf("%d",&b);
    char *inbase;
    FOR(i, 1, MAXN){
        inbase = toBase(i * i, b);
        if (isPalindrome(inbase)){
            printf("%s %s\n", flip(toBase(i, b)), inbase);
        }
    }
    return 0;
}

char* toBase(int num, int base){
    char *inbase = new char [MAX_DIGITS];
    int i = 0, digit;
    while(num >= base){
        digit = num % base;
        inbase[i++] = (digit < 10) ? 
            '0' + digit : 'A' + (digit - 10);
        num /= base;
    }
    inbase[i++] = (num < 10) ? 
        '0' + num : 'A' + (num - 10);
    inbase[i] = '\0';
    return inbase;
}

bool isPalindrome(char num[]){
    int l = strlen(num);
    REP(i, l / 2)
        if(num[i] != num[l-i-1])
            return false;
    return true;
}

char* flip (char num[]){
    int l = strlen(num), temp;
    REP(i, l/2){
        temp = num[i];
        num[i] = num[l-i-1];
        num[l-i-1] = temp;
    }
    return num;
}
