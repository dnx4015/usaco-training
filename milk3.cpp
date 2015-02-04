/*
ID: diana.n1
PROG: milk3
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define MAX_CAP 21

bool status[MAX_CAP][MAX_CAP][MAX_CAP];
int capA, capB, capC;
vector<int>restC;

void mixMilk(int a, int b, int c);
int calcQuant(int giver, int receiver, int cap);

int main(){
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    scanf("%d %d %d",&capA, &capB, &capC);
	mixMilk(0, 0, capC);
	sort(restC.begin(), restC.end());
	int l = restC.size();
	REP(i, l)
		printf("%d%c",restC[i], (i == (l-1))? '\n':' ');
    return 0;
}

void mixMilk (int a, int b, int c){
	if (status[a][b][c])
		return;
	status[a][b][c] = true;
	if ( a == 0 )
		restC.push_back(c);
	int quant = calcQuant(a, b, capB);
	if(quant > 0) mixMilk(a - quant, b + quant, c);	
	quant = calcQuant(a, c, capC);
	if(quant > 0) mixMilk(a - quant, b, c + quant);	
	quant = calcQuant(b, a, capA);
	if(quant > 0) mixMilk(a + quant, b - quant, c);	
	quant = calcQuant(b, c, capC);
	if(quant > 0) mixMilk(a, b - quant, c + quant);	
	quant = calcQuant(c, a, capA);
	if(quant > 0) mixMilk(a + quant, b, c - quant);		
	quant = calcQuant(c, b, capB);
	if(quant > 0) mixMilk(a, b + quant, c - quant);	
}

int calcQuant(int giver, int receiver, int cap){
	return min(cap-receiver, giver);
}
