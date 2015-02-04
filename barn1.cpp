/*
ID: diana.n1
PROG: barn1
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

#define MAX_STALLS 200

typedef struct Group Group;
struct Group{
    int ini, last, dist;
    bool operator < (const Group &g) const{
        if(dist == g.dist)
            return ini < g.ini;
        return dist < g.dist;
    }
};

typedef vector < Group > vector_group;
vector_group groups;

int stallsOccupied[MAX_STALLS] = {0};

void readCows(int cows);
void createGroups(int stalls);
int getTotal(int boards);

int main(){
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    
    int boards, stalls, cows;
    scanf("%d %d %d",&boards, &stalls, &cows);
    
    readCows(cows);
    createGroups(stalls);
    
    sort(groups.begin(), groups.end());
  
    int total = getTotal(boards); 
    printf("%d\n",total);
    
    return 0;
}

void readCows(int cows){
    int stallNum;
    REP(i, cows){
        scanf("%d", &stallNum);
        stallsOccupied[stallNum - 1] = 1;
    }
}

void createGroups(int stalls){
    int size = 0, last = -100;
    REP(i, stalls){
        if (stallsOccupied[i] == 1){
            if(size <= 0){
                groups.push_back({i,i,stalls+1});
                size++;
            }else{
                if(i - 1 == last ){
                    groups[size-1].last = i;
                }else{
                    groups.push_back({i,i,stalls+1});
                    groups[size-1].dist = i-groups[size-1].last-1;
                    size++;
                }
            }
            last = i;
        }
    }
    
}

int getTotal(int boards){
    int numGroups = groups.size(), 
        numMixes = numGroups - min(boards, numGroups),
        swapGroup, nextIni;
    
    FOR(i, 0, numMixes-1){
        nextIni = groups[i].last + groups[i].dist + 1;
        FOR(j, i+1, numGroups){
            if(groups[j].ini == nextIni){
                groups[j].ini = groups[i].ini;
                break;

            }
        }
    }
    
    int total = 0;
    FOR(i, numMixes, numGroups - 1){
        total += (groups[i].last - groups[i].ini + 1);
    }
    return total;
}
