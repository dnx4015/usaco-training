/*
ID: diana.n1
PROG: sort3 
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

#define MAX_N 1002

int arr[MAX_N];

void swap(int i, int j);

int main(){
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    int n;
    scanf("%d",&n);
	
	int n1 = 0, n2 = 0;
	REP(i, n){
		scanf("%d", &arr[i]);
		if(arr[i] == 1) n1++;
		else if (arr[i] == 2) n2++;
	}

	int index[4];	
	int lastIndex1 = n1-1, lastIndex2 = n1+n2-1,
		i = n-1, num = 3, cantSwaps = 0, j; 
	index[1] = lastIndex1; index[2] = lastIndex2; 
	
	while(i >= n1){
		if (i == lastIndex2) {
			num = 2; 
			index[1] = lastIndex1;
		}
		if (arr[i] != num) {
			j = index[arr[i]];
			while(j >= 0 && arr[j] != num) j--;
			if(j < 0 && arr[i] == 1) {
				index[1] = lastIndex2;
				continue;
			}
			//printf("swap: a[%d]=%d and a[%d]=%d\n", 
			//		i, arr[i], j, arr[j]);
			index[arr[i]] = j-1;
			swap(i, j);
			cantSwaps++;
		}
		i--;
	}
    
	printf("%d\n",cantSwaps);
    return 0;
}

void swap(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

