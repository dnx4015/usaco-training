/*
ID: diana.n1
PROG:subset
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

#define MAX 39
#define MAXSUM 390
int nums[MAX + 2];
int memo[MAX+5][MAXSUM+5];

int partitions(int digit, int sum, int max);

int main(){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int n;
	memset(memo, -1, sizeof memo);
    scanf("%d",&n);
	REP(i, n+1)
		nums[i] = i;
	
	int max = n * (n+1);
	if (max % 4){
		printf("0\n");
		return 0;
	}
	
	max /= 4;
	if(n == max){
		printf("1\n");
		return 0;
	}
		
	int quant = 0;
    for(int i = n-1; i > n/2; i--)
		quant += partitions(i, n, max);
	
	printf("%d\n",quant);
    return 0;
}

int partitions(int digit, int sum, int max){
	if (sum + digit > max) return 0;
	if (sum + digit == max) return 1;
	
	int &quant = memo[digit][sum];
	if (quant != -1) return quant;
	quant = 0;
	for (int i = digit-1; i>0; i--){
		quant += partitions(i, sum+digit, max);
	}
	return quant;
}

