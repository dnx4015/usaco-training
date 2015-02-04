/*
ID: diana.n1
PROG: castle
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define INC(i,a,b, inc) for(int i=a;i<=b;i+=inc)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#define MAX 50
#define NONE 0
#define MARK -2

struct Door{
	int row, col, sum;
	char side;
	Door(int r, int c, char s, int sum):
		row(r), col(c), side(s), sum(sum){}
	bool operator < (const Door &p) const{
		if ( sum != p.sum )
			return sum < p.sum;
		if ( col != p.col )
			return col > p.col;//west
		if ( row != p.row )
			return row < p.row;//south
		return (p.side == 'N');  
	} 
};

int orientation[] = {1, 2, 4, 8}; //W, N, E, S
int dr[] = {0,-1,0,1};//W, N, E, S
int dc[] = {-1,0,1,0};//W, N, E, S

int castle [MAX][MAX][2];
int sizes[MAX * MAX + 2];
int m,n;

void printCastle();
int findRooms();
int floodFill(int id);
Door findDoorToBreak();

int main(){
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    scanf("%d %d",&m, &n);
	REP(r, n)
		REP(c, m)
			scanf("%d", &castle[r][c][0]);
	int numRooms = findRooms();
	printf("%d\n", numRooms);
	Door door = findDoorToBreak();
	
	/*printCastle();
	REP(i, numRooms+1)
		printf("%d\t", sizes[i]);
	printf("\n");*/
	
	sort(sizes, sizes + numRooms+1);
	printf("%d\n", sizes[numRooms]);
	printf("%d\n", door.sum);
	printf("%d %d %c\n",door.row, door.col, door.side);
    return 0;
}

int findRooms(){
	int numRooms = 0, size = 0;
	REP(r, n)
		REP(c, m)
			if (castle[r][c][1] == NONE){
				numRooms++;
				castle[r][c][1] = MARK;
				size = floodFill(numRooms);
				sizes[numRooms] = size;
			}
	return numRooms;
}

int floodFill(int id){
	int numVisited = 0, size = 0;
	int nr, nc;
	do{
		numVisited = 0;
		REP(r, n)
			REP(c, m)
				if (castle[r][c][1] == MARK){
					numVisited++; 
					size++;
					castle[r][c][1] = id;
					REP(i, 4){
						if (!(castle[r][c][0] & orientation[i])){
							nr = r + dr[i]; nc = c+dc[i];
							if(castle[nr][nc][1] == NONE)
								castle[nr][nc][1] = MARK;
							
						}
					}
				}
	} while (numVisited != 0);
	return size;
}

void printCastle(){	
	REP(r, n){
		REP(c, m){
			printf("%d\t", castle[r][c][1]);
		}
		printf("\n");
	}

}

Door findDoorToBreak(){
	Door bestDoor = Door(-1, -1, 'C', -1), door = bestDoor;
	int room = 0, prevRoom = 0; 
	for(int r = n-1; r >= 0; r--){
		for(int c = 0; c < m; c++){
			prevRoom = castle[r][c][1];
			if(r-1 >= 0){ 
				room = castle[r-1][c][1];
				if(room != prevRoom){
					door = Door(r+1, c+1, 'N', 
								sizes[prevRoom] + sizes[room]);
					bestDoor = max(bestDoor, door);
				}
			}
			if(c+1 < m){ 
				room = castle[r][c+1][1];
				if(room != prevRoom){
					door = Door(r+1, c+1, 'E', 
								sizes[prevRoom] + sizes[room]);
					bestDoor = max(bestDoor, door);
				}
			}
		}
	}
	return bestDoor;
}
