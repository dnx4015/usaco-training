/*
ID: diana.n1
PROG: preface 
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

#define MAX 3500
#define VOC 7

int counter[MAX+1][VOC] = {0};
int totalCounter[VOC];
char letter[VOC] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int vals[VOC] = {1, 5, 10, 50, 100, 500, 1000};
int maxInd;

void computeCounter(int num);

int main(){
	/*REP(i, MAX+2)
		REP(j, VOC)
			counter[i][j] = -1;*/
    
	freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int n;
    scanf("%d",&n);
	FOR(i, 1, n)
		computeCounter(i);
   	REP(i, maxInd + 1)
		printf("%c %d\n", letter[i], totalCounter[i]);
    return 0;
}

void computeCounter(int rnum){
	int i = rnum < 5 ? 0:
			rnum < 10 ? 1:
			rnum < 50 ? 2:
			rnum < 100 ? 3:
			rnum < 500 ? 4:
			rnum < 1000 ? 5:
			6;
	int q, r, num = rnum;
	//char nums[100];
	//int c = 0;
	REP(j, VOC)
		counter[rnum][j] = 0;

	while ( num > 0 ) {
		if (counter[num][0] != -1 && num != rnum){
			REP(j, VOC)
				counter[rnum][j] += counter[num][j];
			break;
		}				
		q = num/vals[i];
		r = num%vals[i];
		if (q < 0) {
			i--;
			continue;
		}
		if(num == 9 || 
			(num >= 90 && num < 100) || 
			(num >= 900 && num < 1000)){
			counter[rnum][i+1]++;
			counter[rnum][i-1]++;
			num -= (vals[i+1] - vals[i-1]);
			maxInd = max(i+1, maxInd);
			//nums[c++]=letter[i-1];
			//nums[c++]=letter[i+1];
		}else if (q < 4){
			REP(j, q){
				counter[rnum][i]++;
				//nums[c++] = letter[i];
			}
			num -= (q*vals[i]);
			maxInd = max(i, maxInd);
		} else{ //(q == 4)
			counter[rnum][i+1]++;
			counter[rnum][i]++;
			num -= (vals[i+1] - vals[i]);
			maxInd = max(i+1, maxInd);
			//nums[c++]=letter[i];
			//nums[c++]=letter[i+1];
		}
	}
	//nums[c]='\0';
	//printf("%d=>%s\n", rnum, nums);

	REP(i, VOC)
		totalCounter[i] += counter[rnum][i];
}
