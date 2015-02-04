/*
ID: diana.n1
PROG: frac1 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define INC(i,a,b,inc) for(int i=a;i<=b;i+=inc)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#define MAX 160

struct frac{
	int num, den;
	frac(int n, int d): num(n), den(d){}
	bool operator < (const frac &p ) const{
		return num * p.den < p.num * den;	
	}
};
typedef vector < frac > vector_frac;

bool not_prime[MAX];
int n;
int primes[MAX];
int nprimes;
vector_frac list_frac;

void calcCriba(int maxVal);
bool isReduced(int num, int den);

int main(){
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    scanf("%d",&n);
	
	FOR(i, 2, n)
		list_frac.pb(frac(1,i));	
	
	calcCriba(n);
	int inc = 1;
    FOR(num, 2, n-1){
		inc = !(num % 2) ? 2 : 1;
		INC(den, num + 1, n, inc)
			if (isReduced(num, den))
				list_frac.pb(frac(num, den));
	}
	
	sort(list_frac.begin(), list_frac.end());
	
	int l = list_frac.size();
	printf("0/1\n");
	REP(i, l)
		printf("%d/%d\n", list_frac[i].num, list_frac[i].den);
	printf("1/1\n");
	
	return 0;
}

void calcCriba(int maxVal){
	not_prime[0] = true; not_prime[1] = true;
	for(int i = 2; i * i < maxVal; i++)
		if(!not_prime[i])
			INC(j, i*2, maxVal, i)
				not_prime[j] = true;
		
	nprimes = 0;
	FOR(i, 2, maxVal)
		if(!not_prime[i]){
			primes[nprimes++] = i;
		}
}

bool isReduced(int num, int den){
	if (!(den % num)) return false;
	REP(i, nprimes){
		if(num * num < primes[i])
			break;
		if(!(num % primes[i]) &&
			!(den % primes[i]))
			return false;
	}
	return true;
}
