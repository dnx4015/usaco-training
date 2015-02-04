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

#define MAX_DIG 7
#define MIN_DIG 3

int a, b, adig, bdig;
int numArr[10], inits[4] = {1,3,7,9};

int toArray(int num, int arr[]);//returns length of array
void createPals(int num, 
				int cant, int goal,
				int mult1, int mult2); 
bool isPrime(int num);

int main(){
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    scanf("%d %d",&a, &b);

	if(a == 5)
		printf("%d\n", 5);
	if(a <= 7 && 7 <= b)
		printf("%d\n", 7)
	if(a <= 11 && 11 <= b)
		printf("%d\n", 11)

	int adig = max(len(a), MIN_DIG), bdig = min(len(b), MAX_DIG);
	adig += (adig % 2 == 0) ? 1 : 0;

	int num, mult;
	FOR(digits, adig, bdig){
		mult = 1;
		if (digits % 2 == 0)
			continue;
			//11 is prime and even num of digits palindrome
		for(int i = 1; i < digits; i++, mult *= 10);
		REP(i, 4){
			num = (digits == 1) ? 
					inits[i] :
					inits[i] * mult + inits[i];
			createPals(num, (digits == 1) ? 1 : 2, digits, 
						mult / 10, 10);
		}
	}
    
	return 0;
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

void createPals(int num, int dig, int goal, int mult1, int mult2){
	if(dig == goal){
		if(num >= a && num <= b && isPrime(num))
			printf("%d\n", num);
		return;
	}
	int n;
	REP(i, 10){
		if(mult1 == mult2){
			n = num + i * mult1;
			createPals(n, dig + 1, goal, 0,0);
		}else{
			n = num + i * mult1 + i * mult2;
			createPals(n, dig + 2, goal, mult1/10, mult2*10);
		}
	}
	
}

bool isPrime(int num){
	if(num % 2 == 0 || num == 1) return false;
	for(int i = 3; i*i <= num; i+=2)
		if(num % i == 0)
			return false;
	return true;
}
