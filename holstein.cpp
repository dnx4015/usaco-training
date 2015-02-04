/*
ID: diana.n1
PROG: holstein
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

#define MAX_V 26
#define MAX_G 16

int v, g;
int vits[MAX_V];
int food[MAX_G][MAX_V];
int sum[MAX_V];
int list[MAX_G];
int min_quant;
bool done;

void testFood(int index, int current, int limit);
void add(int index, int prod);
bool testSum();

int main(){
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    scanf("%d",&v);
	REP(i, v) scanf("%d", &vits[i]);
	scanf("%d", &g);
	REP(i, g) 
		REP(j, v)
			scanf("%d", &food[i][j]);
	min_quant = g+1;
	done = false;
	FOR(limit, 1, g){
		FOR(i, 0, g-limit){
			testFood(i, 0, limit);
			if(done)
				goto hell;
		}
	}
	
hell:
    printf("%d ",min_quant);
	REP(i, min_quant)
		printf("%d%c", list[i], (i+1 < min_quant) ? ' ' : '\n');
    return 0;
}

void testFood(int i, int current, int limit){
	if (current >= limit || done){
		return;
	}
	add(i, 1);
	list[current++] = i+1;
	if (testSum()){
		min_quant = current;
		done = true;
		return;
	}
	if (current < limit){
		FOR(j, list[current-1], g){
			testFood(j, current, limit);
			if(done)
				return;
		}	
	}
	list[--current] = 0;
	add(i, -1);
}

void add(int index, int prod){
	REP(i, v)
		sum[i] += food[index][i]*prod;
}

bool testSum(){
	REP(i, v){
		if(sum[i] < vits[i])
			return false;
	}
	return true;
}
