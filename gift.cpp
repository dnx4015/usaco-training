/*
ID: diana.n1
PROG: gift1
LANG: C++
*/

#include <cstdio>
#include <cstring>

#define MAX_NP 10

using namespace std;

int getId(char names[][14], char* nameId, int np){
    
    for (int i = 0; i < np; i++){
        if(strcmp(names[i], nameId) == 0)
            return i;
    }
    return -1;
}

int main(){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    

    int np;
    scanf("%d",&np);
    
    char names[MAX_NP][14];
    int money[MAX_NP][2];
    for(int i = 0; i < np; i++){
        scanf("%s", &names[i][0]);
        money[i][0] = 0;
        money[i][1] = 0;
    }
    
    char *giver = new char [14], 
        *receiver = new char[14];
    int id = -1, friendsNum = 0, 
        moneyGift = 0, gift = 0, rest = 0;
    
    
    while(scanf("%s", giver) != EOF){
        id = getId(names, giver, np);
        if(id == -1){
            printf("not found: %s", giver);
            return 0;
        }
        
        scanf("%d %d", &moneyGift, &friendsNum);
        if(moneyGift <= 0 || friendsNum <= 0){
            continue;
        }
        gift = moneyGift / friendsNum;
        rest = moneyGift % friendsNum;
        money[id][0] = moneyGift;
        money[id][1] += rest;
        
        for (int i = 0; i < friendsNum; i++){
            scanf("%s", receiver);
            id = getId(names, receiver, np);
            if(id == -1){
                printf("not found: %s", receiver);
                return 0;
            }
            money[id][1] += gift;
        }
    }
    
    for(int i = 0; i < np; i++){
        printf("%s %d\n", names[i], money[i][1] - money[i][0]);
    }

    return 0;
}

