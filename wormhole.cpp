/*
ID: diana.n1
PROG: wormhole 
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

#define MAX 12

struct Point{
	int x, y, pair;
	Point():x(-1), y(-1), pair(-1){}
	Point(int x, int y):x(x), y(y), pair(-1){}
	bool operator < (const Point &p) const{
		if (y == p.y)
			return x < p.x;
		return y < p.y;
	}
	bool operator == (Point p){
		return (y == p.y ) && (x == p.x);
	}
	bool operator != (Point p){
		return (y != p.y ) || (x != p.x);
	}
	bool hasPair(){return pair != -1;}
	void setPair(int p){pair = p;}
};

Point map [MAX+2];
int n, cycles;

void make_pairs(int ini);
int getNext(int ini);
bool make_pair(int i, int j);
void unmake_pair(int i, int j);
void test_pairs();
bool test_cycle(Point origin);

int main(){
    IOR("wormhole.in");
    IOW("wormhole.out");
    scanf("%d",&n);
	int x, y;
	REP(i, n){
		scanf("%d %d", &x, &y);
		map[i] = Point(x,y);
	}
	sort(map, map+n);
	make_pairs(0);
    printf("%d\n",cycles);
    return 0;
}

void make_pairs(int ini){
	if ( ini >= n || map[ini].hasPair()){
		test_pairs();
		return;
	}
	FOR(i, ini+1, n-1){
		if(make_pair(ini, i)){
			make_pairs(getNext(ini+1));
			unmake_pair(ini, i);
		}
	}	
}

bool make_pair(int i, int j){
	if (!map[i].hasPair() && !map[j].hasPair()){
		//DEBUG printf("make pair %d %d\n", i, j);
		map[i].setPair(j);
		map[j].setPair(i);
		return true;
	}	
	return false;
}

int getNext(int ini){
	while(map[ini].hasPair()){
		ini++;	
	}
	return ini;
}

void unmake_pair(int i, int j){
	map[i].setPair(-1);
	map[j].setPair(-1);
}

void test_pairs(){
	REP(i, n)
		if(!map[i].hasPair())
			return;
	DEBUG
		REP(i, n)
			if(map[i].pair > i)
				printf("pair: %d -> %d\n", i, map[i].pair);

	REP(i, n)
		if(map[i].pair > i){
			if(test_cycle(map[i])){
				DEBUG printf("found cycle\n");
				cycles++;
				break;
			}else{
				DEBUG printf("no cycle found\n");	
			}
		}
}

bool test_cycle(Point origin){
	int exit = origin.pair, init = map[exit].pair;
	if( map[exit].y == map[init].y &&
		exit == init + 1){
		return true;
	}
	//while( map[init] != origin){
	do{
		DEBUG printf("point:%d %d vs origin: %d %d\n", 
				map[exit].x, map[exit].y, origin.x, origin.y);
		init = exit + 1;
		if ( init < n && map[init].y == map[exit].y)
			exit = map[init].pair;
		else
			return false;
	} while(map[init] != origin);
	return true;
}

