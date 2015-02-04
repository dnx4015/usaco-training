/*
ID: diana.n1
PROG: milk2
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 5000;

typedef vector< pair<int, int> > pair_vector;

bool cmpPair (pair<int, int> i, pair<int, int> j){
    return i.first < j.first;
}

int main(){
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n;
    scanf("%d",&n);
    
    pair_vector schedules;
    int init, end;
    for (int i = 0; i < n; i++){
        scanf("%d %d", &init, &end);
        schedules.push_back(make_pair(init, end));
    } 
    sort(schedules.begin(), schedules.end(), cmpPair);
   
    int ranges = 0;
    for (int i = 1; i < n; i++){
        if( schedules[i].first > schedules[ranges].second ){
            schedules[++ranges] = schedules[i];
        }else if ( schedules[i].second > schedules[ranges].second ){
            schedules[ranges].second = schedules[i].second;
        }
    }
   
    ranges++;
    int noMilk = 0, onMilk = 0;
    int maxNoMilk = 0, maxOnMilk = 0;
    maxOnMilk = schedules[0].second - schedules[0].first;
    for (int i = 1; i < ranges; i++){
        noMilk = schedules[i].first - schedules[i - 1].second;
        maxNoMilk = max(noMilk, maxNoMilk);

        onMilk = schedules[i].second - schedules[i].first;
        maxOnMilk = max(onMilk, maxOnMilk);
    }

    printf ("%d %d\n", maxOnMilk, maxNoMilk);
    return 0;
}

