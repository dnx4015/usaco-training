/*
ID: diana.n1
PROG: combo
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

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define DIALS 3
#define DIFF 2
#define MAX 250
#define MAX_N 100
	
int n;
int vals1[5];
int vals2[5];

int calcReps(int combo1[], int combo2[]);
int countIntersect(int combo1, int combo2);

int main(){
    IOR("combo.in");
    IOW("combo.out");
	int combo1[DIALS], combo2[DIALS]; 
    scanf("%d",&n);
	REP(i, DIALS)
		scanf("%d", &combo1[i]);	
	REP(i, DIALS)
		scanf("%d", &combo2[i]);
	
	if (n >= 5){
		int reps = calcReps(combo1, combo2);
		printf("%d\n", MAX - reps);
	}else{
		printf("%d\n", n*n*n);
	}
    return 0;
}

int calcReps(int combo1[], int combo2[]){
	int x_count = countIntersect(combo1[0]-2, combo2[0]-2);
	if (x_count <= 0) return 0;

	int y_count = countIntersect(combo1[1]-2, combo2[1]-2);
	if (y_count <= 0) return 0;
	
	int z_count = countIntersect(combo1[2]-2, combo2[2]-2);
	if (z_count <= 0) return 0;
	
	return x_count * y_count * z_count;
}

int countIntersect(int combo1, int combo2){
	REP(i, 5){
		vals1[i] = (combo1 + i) % n;
		if (vals1[i] <= 0) vals1[i] += n;
		vals2[i] = (combo2 + i) % n;
		if (vals2[i] <= 0) vals2[i] += n;
	}
	int count = 0;
	REP (i, 5)
		REP (j, 5)
			if (vals1[i] == vals2[j])
				count++;
	return count;
}
