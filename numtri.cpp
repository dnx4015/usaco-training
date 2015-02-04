/*
ID: diana.n1
PROG: numtri 
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
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#define MAX 1002

int rows;
int line[2][MAX];

int processTree();

int main(){
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    scanf("%d",&rows);
	int best = processTree();
    printf("%d\n", best);
    return 0;
}

int processTree(){
	int best = 0, current = 1, before = 0;
	FOR(r, 1, rows){
		FOR(c, 1, r){
			scanf("%d", &line[current][c]);
			line[current][c] += max(line[before][c], 
									line[before][c-1]);
			best = max(best, line[current][c]);
		}
		current ^= 1; before ^= 1;
	}
	return best;
}

