/*
ID: diana.n1
PROG: skidesign 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

#define IOR(x) freopen(x,"r",stdin);
#define IOW(x) freopen(x,"w",stdout);
#define DEBUG if(0)

#define i64 long long
#define u64 unsigned long long
#define eps 1e-10

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORIT(it,p) for(__typeof(p.end()) it=p.begin();it!=p.end();it++)
#define INC(i,a,b, inc) for(int i=a;i<=b;i+=inc)

#define mset(p,v) memset(p,v,sizeof(p))
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#define MAX 1000
#define DIFF 17
#define INF 2000000000

int hills[MAX+2];

int minCost(int n, int min, int max);

int main(){
    IOR("skidesign.in");
    IOW("skidesign.out");
    int n;
    scanf("%d",&n);
	REP(i, n)
    	scanf("%d",&hills[i]);
	sort(hills, hills+n);
	int min = hills[0],max = hills[n-1];
	if(max - min <= 17)
    	printf("%d\n",0);
	else
		printf("%d\n", minCost(n, min, max));
    return 0;
}

int minCost(int n, int min, int max){
	int minCost = INF, cost, nMax, nMin;
	REP(i, max - min - DIFF){
		cost = 0; 
		nMax = max - i;
		nMin = nMax - 17;
		REP(j, n){
			if (hills[j] < nMin)
				cost += (nMin - hills[j])*
						(nMin - hills[j]);
			else break;
		}	
		for(int j = n-1; j >= 0; j--){
			if (hills[j] > nMax)
				cost += (hills[j] - nMax)*
						(hills[j] - nMax);
			else break;
		}
		if (cost < minCost)
			minCost = cost;
		else
			return minCost;	
	}
	return minCost;
}
