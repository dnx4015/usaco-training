/*
ID: diana.n1
PROG: dualpal 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)

#define MAXN 2000000000
#define MAX_DIGITS 35

bool isPalindrome(int num, int base);

int main(){
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s, baseQuant;
    scanf("%d %d",&n, &s);
    FOR(i, s + 1, MAXN){
        if(n == 0) break;
        baseQuant = 2;
        RFOR(base, 10, 2){
            if(baseQuant == 0) break;
            if(isPalindrome(i, base))
                baseQuant--;
        }
        if(baseQuant == 0){
            n--;
            printf("%d\n", i);
        }
    }
    return 0;
}

bool isPalindrome(int num, int base){
    char *inbase = new char [MAX_DIGITS];
    int i = 0, digit, l;
    
    while(num >= base){
        digit = num % base;
        inbase[i++] = (digit < 10) ? 
            '0' + digit : 'A' + (digit - 10);
        num /= base;
    }
    inbase[i++] = (num < 10) ? 
        '0' + num : 'A' + (num - 10);
    inbase[i] = '\0';
    
    l = strlen(inbase);
    REP(i, l / 2)
        if(inbase[i] != inbase[l-i-1])
            return false;
    return true;
}

