/*
ID: diana.n1
PROG: dp 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define INC(i,a,b, inc) for(int i=a;i<=b;i+=inc)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#define MAXN 2000

int main(){
    freopen("dp.in", "r", stdin);
    freopen("dp.out", "w", stdout);
    int num[MAXN], bestrun[MAXN], n, best = 0;
    scanf("%d",&n);
	REP(i, n) {
		bestrun[i] = -1;
		scanf("%d", &num[i]);
		REP(k, i+1)
			if(bestrun[k] <= num[i]){
				if(bestrun[k]== -1) best++;
				bestrun[k] = num[i];
				break;
			}
	}
    printf("%d\n", best);
    return 0;
}

