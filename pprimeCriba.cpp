/*
ID: diana.n1
PROG: pprime
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

#define MAX 99999989

bool not_prime[MAX+1];
int a, b;
int numArr[10];

void calcCriba(int max);
int toArray(int num, int arr[]);//returns length of array
bool isPalindrome(int num);

int main(){
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    scanf("%d %d",&a, &b);
	calcCriba(MAX);
/*	int maxPrime = 0;
	FOR(i, 9973, MAX){
		if(!not_prime[i])
			maxPrime = max(maxPrime, i);	
	}
	printf("%d", maxPrime);*/
    FOR(i, a, b)
		if(i < MAX)
			if(!not_prime[i])
				if (isPalindrome(i))
					printf("%d\n", i);
    return 0;
}

void calcCriba(int maxVal){
	not_prime[0] = true; not_prime[1] = true;
	for(int i = 2; i * i < maxVal; i++)
		if(!not_prime[i])
			INC(j, i*2, maxVal, i)
				not_prime[j] = true;
}

int toArray(int num, int arr[]){
	int i = 0;
	while (num > 0){
		arr[i] = num % 10;
		num /= 10;
		i++;
	}
	return i;
}

bool isPalindrome(int num){
	int n = toArray(num, numArr);	
	REP(i, n/2)
		if(numArr[i]!=numArr[n-i-1])
			return false;
	return true;
}
