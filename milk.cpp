/*
ID: diana.n1
PROG: milk
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define MAX_MILK 2000000
#define MAX_FARMERS 5000

typedef vector < pair <int, int> > vector_pair;

int main(){
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int neededMilk, farmers;
    scanf("%d %d",&neededMilk, &farmers);
    
    vector_pair availableMilk;
    int cost, gallons;
    REP(i, farmers){
        scanf("%d %d", &cost, &gallons);
        availableMilk.push_back(make_pair(cost, gallons));
    }
    sort(availableMilk.begin(), availableMilk.end());
    
    int l = availableMilk.size(), totalCost = 0;
    REP(i, l){
        if ( neededMilk <= 0 ) break;
        gallons = min(availableMilk[i].second, neededMilk);
        totalCost += availableMilk[i].first * gallons;
        neededMilk -= gallons;
    }
    printf("%d\n",totalCost);
    return 0;
}

