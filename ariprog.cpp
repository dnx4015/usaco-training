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

#define MAX_VAL 251

typedef vector < pair <int, int> > vector_pair;

int depthVal, maxVal;
bool nums[MAX_VAL * MAX_VAL * 2];
vector_pair listSeq;

void createNums();
void computeSeq(int ini, int last, int depth, int diff);

int main(){
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d %d",&depthVal, &maxVal);
    createNums();
    maxVal = maxVal * maxVal * 2 + 1;
    REP(i, maxVal){
        computeSeq(i, -1, 1, -1);
    }
    int l = listSeq.size();
    if(l <= 0) {
        printf("NONE\n");
    }else{
        sort(listSeq.begin(), listSeq.end());
        REP(i, l)
            printf("%d %d\n", listSeq[i].second, listSeq[i].first);
    }
    return 0;
}

void createNums(){
    REP(p, maxVal+1)
        REP(q, maxVal+1)
            nums[p*p+q*q]=true;
}

void computeSeq(int ini, int last, int depth, int diff){
    if(depth >= depthVal){
        listSeq.push_back(make_pair(diff, ini));
        return;
    }
    if (!nums[ini])
        return;
    FOR(i, ini+1, maxVal){
        if(nums[i]){
            if(diff == -1){
                computeSeq(ini, i, depth+1, i - ini);
            }else if((i - last) == diff){
                computeSeq(ini, i, depth+1, diff);
            }
        }
    }    
}
