/*
ID: diana.n1
PROG: sprime
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

int init[4] = {2, 3, 5, 7}, dict[4] = {1, 3, 7, 9};
int n;

bool isPrime(int num);
void sprime(int num, int dig);

int main(){
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
	
    scanf("%d",&n);
	REP(i, 4)
		sprime(init[i], 1);
    
	return 0;
}

void sprime(int num, int dig){
	if(dig == n){
		printf("%d\n", num);
		return;
	}
	
	int newNum;
	REP(i, 4){
		newNum = num * 10 + dict[i];
		if(isPrime(newNum))
			sprime(newNum, dig + 1);
	}
}

bool isPrime(int num){
	if(num % 2 == 0 || num == 1) return false;
	for(int i = 3; i*i <= num; i+=2)
		if(num % i == 0)
			return false;
	return true;
}
