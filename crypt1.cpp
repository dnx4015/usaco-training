/*
ID: diana.n1
PROG: crypt1 
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define MAX_DIGITS 10
#define NUM_DIG_PARTIAL 3
#define NUM_DIG_RESULT 4

bool available[MAX_DIGITS];
int digits[MAX_DIGITS];

int getCryptarithms(int n);
bool isCryptarithm(int num1, int num2);
bool inAvailable(int num, int numDigits);

int main(){
    REP(i,MAX_DIGITS + 1) digits[i] = false;
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int n, digit;
    scanf("%d",&n);
    REP(i, n){
        scanf("%d", &digit);
        digits[i] = digit;
        available[digit] = true;
    }

    int results = getCryptarithms(n);
    printf("%d\n",results);
    return 0;
}

int getCryptarithms(int numAvailable){
    int num1, num2, cant = 0;
    REP(i, numAvailable)
        REP(j, numAvailable)
            REP(k, numAvailable){
                num1 = digits[i]*100 + 
                        digits[j]*10+
                        digits[k];
                REP(l, numAvailable)
                    REP(m,numAvailable){
                        num2 = digits[l]*10+
                                digits[m];
                        if (isCryptarithm(num1, num2)){
                            cant++;
                        }
                    }
            }
    return cant;
}

bool isCryptarithm(int num1, int num2){
    int partial1 = num1 * (num2 % 10), 
        partial2 = num1 * (num2 / 10), 
        result = num1 * num2;
    return (inAvailable(partial1, NUM_DIG_PARTIAL) &&
            inAvailable(partial2, NUM_DIG_PARTIAL) &&
            inAvailable(result, NUM_DIG_RESULT));
}

bool inAvailable(int num, int numDigits){
    int div = (numDigits == NUM_DIG_PARTIAL) ? 100 : 1000;
    int digit;
    if(num / div < 10){
        while(num > 0){
            digit = num % 10;
            num /= 10;
            if(!available[digit]){
                return false;
            }
        }
        return true;
    }
    return false;
}


