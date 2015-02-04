/*
ID: diana.n1
PROG: calfflac
LANG: C++
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define MAX_CHAR 4502
#define MAX_TMP 82
#define MAX_PAL 2002

typedef struct Palindrome Palindrome;
struct Palindrome{
    int ini, end, len;
    bool operator < (const Palindrome p)const{
        return len < p.len;
    }
};

Palindrome getPalindromeAt(string, int, int);

int main(){
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    string complete, tmp;
    while( getline(cin, tmp) != NULL){
        if(complete.size() > 0)
            complete += "\n";
        complete += tmp;
    }
    
    int l = complete.size();
    Palindrome longest = {0,0,1}, pal;
    FOR(i,1,l-1){
        if ( !isalpha(complete[i]) ) continue;
        pal = getPalindromeAt(complete, i, i);
        //printf("%d: %d, %d => %d\n", i, pal.ini, pal.end, pal.len);
        longest = (longest < pal) ?  pal : longest;
        pal = getPalindromeAt(complete, i, i + 1);
        //printf("%d: %d, %d => %d\n", i, pal.ini, pal.end, pal.len);
        longest = (longest < pal) ?  pal : longest;
    }
    string result;
    result = complete.substr(longest.ini, longest.end - longest.ini + 1);
    cout << longest.len <<"\n"<< result <<"\n";
    return 0;
}

Palindrome getPalindromeAt(string str, int ini, int end){
    int l = 0, lastIni = ini, lastEnd = end,
        len = str.size(), equal = true;
    while ( ini >= 0 && end < len && equal) {
        while ( ini >= 0 && !isalpha(str[ini]) ) ini--;
        while ( end < len && !isalpha(str[end]) ) end++;
        if ( toupper(str[ini]) == toupper(str[end]) ){
            //printf("%c == %c \n", str[ini], str[end]);
            l += (ini == end) ? 1 : 2;
            lastIni = ini; lastEnd = end;
            ini--; end++;
        }else{
            equal = false;
            //printf("%c != %c \n", str[ini], str[end]);
        }
    }
    return {lastIni, lastEnd, l};
}
