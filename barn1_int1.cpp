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
    int ini;
    int end;
    int quant;
    Group *next;
    int dist;
};

bool cmpGroup( Group ga, Group gb){
    if (ga.dist == gb.dist)
        return ga.ini < gb.ini;
    return ga.dist < gb.dist;
}

typedef vector < Group > vector_group;
vector_group groups;

int stallsOccupied[MAX_STALLS] = {0};

void readCows(int cows);
void createGroups(int stalls);
int getTotal(int boards);

int main(){
    freopen("barn1.in", "r", stdin);
    //freopen("barn1.out", "w", stdout);
    
    int boards, stalls, cows;
    scanf("%d %d %d",&boards, &stalls, &cows);
    readCows(cows);
    createGroups(stalls);
    sort(groups.begin(), groups.end(), cmpGroup);
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
                groups.push_back({i,i,1,NULL,stalls+1});
                size++;
            }else{
                if(i - 1 == last ){
                    groups[size-1].end = i;
                    groups[size-1].quant++;
                }else{
                    groups.push_back({i,i,1,NULL,stalls+1});
                    groups[size-1].next = &groups[size];
                    groups[size-1].dist = i-groups[size-1].end-1;
                    size++;
                }
            }
            last = i;
        }
    }
int numGroups = groups.size(),
     printf("ini\tend\tquant\tnext\tdist\n");
    REP(i, numGroups){
        printf("%d\t%d\t%d\t%d\t%d\n", groups[i].ini, 
                groups[i].end, groups[i].quant, 
                (groups[i].next == NULL) ? 0:groups[i].next->ini, 
                groups[i].dist);
    }

}

int getTotal(int boards){
    int numGroups = groups.size(), numMixes = numGroups - boards;
    Group *group;
    
    printf("ini\tend\tquant\tnext\tdist\n");
    REP(i, numGroups){
        printf("%d\t%d\t%d\t%d\t%d\n", groups[i].ini, 
                groups[i].end, groups[i].quant, 
                (groups[i].next == NULL) ? 0:groups[i].next->ini, 
                groups[i].dist);
    }

    FOR(i, 0, numMixes){
        group = groups[i].next;
        group->ini = groups[i].ini;
        group->quant = group->end - group->ini + 1;
    }

 printf("ini\tend\tquant\tnext\tdist\n");
    REP(i, numGroups){
        printf("%d\t%d\t%d\t%d\t%d\n", groups[i].ini, 
                groups[i].end, groups[i].quant, 
                (groups[i].next == NULL) ? 0:groups[i].next->ini, 
                groups[i].dist);
    }

    int total = 0;
    FOR(i, numMixes + 1, numGroups - 1){
        total += groups[i].quant;
    }
    return total;
}
