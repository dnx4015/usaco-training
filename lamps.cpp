/*
ID: diana.n1
PROG: lamps 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
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

#define MAX 100
#define ALL 3

int lampsEnd[MAX+2];
int lamps[MAX];

int exe0[] = {0};
int exe1[] = {1,2,3,4};
int exe2[] = {0,1,2,3,14,24,34};
int all[]  = {0,1,2,3,4,14,24,34};
bool possible = false;

void test(int which[], int l, int n);
void exec(int which, int l);
void cmpLamps(int l);

struct Lamp{
	int vals[MAX];
	int l;
	
	Lamp(int v[], int n):l(n){
		REP(i,l)
			vals[i] = v[i];
	}
	
	bool operator < (const Lamp &p) const{
		REP(i, l)
			if (vals[i] < p.vals[i])
				return true;
			else if (vals[i] > p.vals[i])
				return false;
		return false;
	} 	

	string str(){
		string num = "";
		REP(i, l){
			num += SSTR(vals[i]);
		}
		return num;
	}
};

vector < Lamp > lst;

int main(){
    IOR("lamps.in");
    IOW("lamps.out");
    int n,c;
    scanf("%d %d",&n, &c);
	
	fill_n(lampsEnd, n, -1);
	fill_n(lamps, n, 1);

	int tmp;
	while (1) {
		scanf("%d", &tmp);
		if(tmp == -1) break;
		lampsEnd[tmp-1] = 1;
	}	
	
	while (1){
		scanf("%d", &tmp);
		if(tmp == -1) break;
		lampsEnd[tmp-1] = 0;
	}

	if ( c >= 3) test(all, 8, n);
	else if ( c == 2) test(exe2, 7, n);
	else if ( c == 1) test(exe1, 4, n);
	else test(exe0, 1, n);//0

	if (!possible)
		printf("IMPOSSIBLE\n");

	//REP(i, lst.size())
	//	printf("%s\n", lst[i].str().c_str());

	sort(all(lst));
	REP(i, lst.size())
		printf("%s\n", lst[i].str().c_str());

    return 0;
}

void test(int execs[], int l, int n){
	REP(i, l){
		DEBUG printf("test: %d\n", execs[i]);
		fill_n(lamps, n, 1);
		exec(execs[i] % 10, n);
		if(execs[i] > 10)
			exec(execs[i] / 10, n);
		cmpLamps(n);
	}
}

void exec(int which, int l){
	switch(which){
		case 0:
			return;
		case 1:
			REP(i, l)
				lamps[i] = lamps[i] ? 0 : 1;
			return;
		case 2:
			INC(i, 0, l-1, 2)
				lamps[i] = lamps[i] ? 0 : 1;
			return;
		case 3:
			INC(i, 1, l-1, 2)
				lamps[i] = lamps[i] ? 0 : 1;
			return;	
		case 4:
			INC(i, 0, l-1, 3)
				lamps[i] = lamps[i] ? 0 : 1;
			return;
	}
}

void cmpLamps(int l){
	REP(i, l){
		if(lampsEnd[i] != -1 && (
			lampsEnd[i] != lamps[i]))
		return;
	}
	
	lst.pb(Lamp(lamps, l));
	possible = true;
}
