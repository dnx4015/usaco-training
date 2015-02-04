/*
ID: diana.n1
PROG: friday 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define WEEK 7
#define DIST 5
#define FEB 1
#define MON 2 //SAT = 0, SUN = 1, ...
#define INIT_YEAR 1900


int main(){
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int daysInMonth [] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
    int thirteenCount[7] = {0};
    int n;
    scanf("%d",&n);
   
    int firstDay = MON, thirteenDay;
    n += INIT_YEAR;
    
    for (int year = INIT_YEAR; year < n; year++){
        for (int month = 0; month < 12; month++){
            daysInMonth[FEB] = 0;
            if((year % 400 == 0) || 
                ((year % 100 != 0) && (year % 4 == 0))){
                daysInMonth[FEB] = 1;
            }
            thirteenDay = (firstDay + DIST) % WEEK;
            thirteenCount[thirteenDay]++;
            
            firstDay += daysInMonth[month];
            firstDay %= WEEK;
        }
    }
    
    char spaceChar;
    for (int day = 0; day < WEEK; day++){
        spaceChar = (day + 1 == WEEK) ? '\n' : ' ';
        printf("%d%c", thirteenCount[day], spaceChar);
    }
    return 0;
}

