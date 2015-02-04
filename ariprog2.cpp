/*
ID: diana.n1
PROG: ariprog 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define MAX_VAL 250

typedef vector < pair <int, int> > vector_pair;

int depthVal, maxVal;
bool nums[MAX_VAL * MAX_VAL * 2 + 1];
int dict[MAX_VAL * MAX_VAL * 2 + 1];

int createNums();
bool computeSeq(int total);

int main(){
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d %d",&depthVal, &maxVal);
    int total = createNums();
   /* REP(i, maxVal*2*maxVal+1)
        printf("%d:\t%d\n", i, nums[i] ? 1:0);
    */
    bool found = computeSeq(total);
    if(!found)
        printf("NONE\n"); 
    return 0;
}

int createNums(){
    int i = 0;
    REP(p, maxVal+1)
        FOR(q, p, maxVal){
            if(!nums[p*p+q*q]){
                nums[p*p+q*q]=true;
                dict[i++] = p*p+q*q;
            }
        }
    sort(dict, dict + i);
    return i;
}

bool computeSeq(int total){
    bool found, foundOne = false;
    int mVal = maxVal * maxVal * 2 + 1;
    FOR(b, 1, maxVal*maxVal*2/(depthVal-1)){
        REP(i, total){
            found = true;
            REP(sec, depthVal){
                if ( dict[i]+sec*b >= mVal || 
                     !nums[dict[i]+sec*b] ) {
                    found = false;
                    break;
                }
            }
            if(found){
                printf("%d %d\n",dict[i],b );
                foundOne = true;
            }
        }
    }
    return foundOne;
}
