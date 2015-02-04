/*
ID: diana.n1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string group, comet;
    fin >> group >> comet;

    fout << group <<"  " <<comet << endl;
    return 0;
}
