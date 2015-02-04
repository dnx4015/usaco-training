/*
ID: diana.n1
PROG: hamming
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

#define MAX_NUM 256
#define MAX_LEN 64

int list[MAX_LEN+2];
int n, b, d;
int maxNum;
bool done;

void testSeq(int num, int quant);
int hammingDist(int num, int l);

int main(){
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    scanf("%d %d %d",&n, &b, &d);
	maxNum = pow(2, b);
	done = false;
	FOR(i, 0, maxNum -1){
		list[0] = i;
		testSeq(i, 1);
		if(done)
			goto hell;
	}
	hell:
	sort(list, list+n);
	char c = ' ';
	REP(i, n){
		c = (((i+1)%10 == 0 && i != 0)|| (i+1) == n) ? '\n': ' ';
		printf("%d%c", list[i], c);	
	}
    return 0;
}

void testSeq(int num, int quant){
	if (quant == n){
		done = true;
		return;
	}
	FOR(i, num+1, maxNum-1){
		if( hammingDist(i, quant) >= d){
			list[quant] = i;
			testSeq(i, quant+1);
			if(done)
				return;
		}
	}
}

int hammingDist(int num, int l){
	int diff, dist, minDist = d+1;
	REP(i, l){
		diff = num ^ list[i];
		dist = 0;
		REP(j, b)
			if(((1<<j)&diff))
				dist++;

		//printf("\nhDist: %d, %d = %d => %d\n", num, list[i], diff, dist);
		minDist = min(dist, minDist);
	}
			
	return minDist;
}
	
