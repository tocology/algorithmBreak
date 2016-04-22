#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int N;
 
int dy[] = { 1,1,1};
int dx[] = {-1,0,1};
 
vector<vector<int> > board;
 
void check(int y, int x, int delta){
    board[y][x] += delta;
    for(int j=1; j<N-y; ++j){
        for(int k=0; k<3; ++k){
            int ny = y + j*dy[k];
            int nx = x + j*dx[k];
            if(ny >= 0 && ny < N && nx >= 0 && nx < N)
                board[ny][nx] += delta;
        }
    }
}
 
int count(int y){
 
    if(y == N) return 1;
     
    int ret = 0;
    // x-axis 
    for(int i=0; i<N; ++i){
        // condition: board[y][x] is vailable to put a queen.
        if(!board[y][i]){
            // check other lines where queen can not be put.
            check(y, i, 1);
            // recursively counting queens
            ret += count(y+1);
            // uncheck queen
            check(y, i, -1);
        }
    }
     
    return ret;
}
 
int main(){
     
    scanf("%d", &N);
     
    board = vector<vector<int> >(N, vector<int>(N, 0));
     
    printf("%d", count(0));
     
    return 0;
}