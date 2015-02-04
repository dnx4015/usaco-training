/*
ID: diana.n1
PROG: beads 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define WHITE 'w'

int getMaxBeads(int cant, char* str){
    if(cant < 3)
        return -1;
    char initCar = str[0], car;
    int quant = 1, quantAnt = 0,
        whites = (initCar == WHITE) ? 1 : 0,
        max = -1, sum = 0, i = 1;
    bool looped = false;
    while (i < cant){
        car = str[i];
        if(initCar == WHITE || car == initCar || car == WHITE){
            quant++;
            if(initCar == WHITE && car != WHITE)
                initCar = car;
            whites = (car == WHITE) ? (whites + 1) : 0;
        }else{ //initCar != WHITE && car != initCar && car != WHITE
            initCar = car;
            sum = quant + quantAnt;
            max = (sum > max) ? sum : max;
            quantAnt = quant - whites;
            quant = 1 + whites;
            whites = 0;
            if (looped)
                break;
        }
        i++;
        if(i >= cant && !looped){
            looped = true;
            i = 0;
        }
    }
    max = (max == -1) ? quant : max;
    return (max > cant) ?  cant : max;
}

int main(){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int cant;
    char *str = new char [350];
    scanf("%d %s",&cant, str);
    int max = getMaxBeads(cant, str);
    printf("%d\n", max);
    return 0;
}

