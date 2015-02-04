/*
ID: diana.n1
PROG: runround 
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

#define MAX 10
#define MAX_NUM 1000000000
//#define MAX_NUM 1000

int next[MAX][MAX];
int num[MAX];
int counter[MAX];
int digit[MAX];

int getNextRunRound(int min);
int storeNum(int n);
void computeNext(int l);
bool testRunRound(int i, int &l);
int addOne(int l);

int main(){
    IOR("runround.in");
    IOW("runround.out");
    int n, runround;
    scanf("%d",&n);
	runround = getNextRunRound(n);
    printf("%d\n", runround);
    return 0;
}

int getNextRunRound(int min){
	int l = storeNum(min);
	computeNext(l);
	FOR(i, min+1, MAX_NUM){
		if(testRunRound(i, l))
			return i;
		if(l > 9)
			return 0;
	}
	return 0;
}

int storeNum(int n){
	int i = 0;
	while (n > 0){
		num[i++] = n % 10;
		n /= 10;
	}
	return i;
}

void computeNext(int l){
	REP(i, MAX)
		REP(j,l)
			next[i][j] = (i+j) % l;
}

bool testRunRound(int n, int &l){
	int nl = addOne(l);
	if(nl != l){
		l = nl;
		computeNext(nl);
		return false;
	}

	REP(i, l)
		counter[i] = 0;
	
	int pos = next[num[l - 1]][0], q = 1;

	while (pos > 0) {
		if (digit[num[l-pos-1]] > 1)
			return false;
		if (counter[pos] > 0)
			return false;
		counter[pos]++;
		pos = next[num[l-pos-1]][pos];
		q++;
	}
	return (q == l);
}

int addOne(int l){
	int carry = 1;
	REP(i, MAX)
		digit[i] = 0;
	string str = "";

	REP(i, l){
		num[i] += carry;
		if (num[i] >= MAX) {
			num[i] = 0;
			carry = 1;
		}else{
			carry = 0;
		}
		digit[num[i]]++;
		DEBUG str = SSTR(num[i]) + str;
	}
	
	if (carry > 0){
		num[l++] = carry;
		digit[num[l-1]]++;
		DEBUG str = SSTR(num[l - 1]) + str;
	}
	DEBUG printf("num %s\n", str.c_str());
	return l;
}
