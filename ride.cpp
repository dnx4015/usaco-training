/*
ID: diana.n1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#define MOD_VAL 47

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string group, comet, result;
    int groupNum = 1, cometNum = 1;
    
    fin >> group >> comet;
    for(int i=0; i < group.length(); i++){
        groupNum *= int(group[i]) - int('A') + 1;
    }
    for(int i=0; i < comet.length(); i++){
        cometNum *= int(comet[i]) - int('A') + 1;
    }
    
    result = ((groupNum % MOD_VAL) == (cometNum % MOD_VAL))? "GO" : "STAY";
    fout << result << endl;
    return 0;
}
