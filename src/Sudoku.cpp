#include <cstdio>

using namespace std;

int board[9][9];

bool check(int y, int x){

    // y axis
    for(int i=0; i<9; ++i)
        if(board[i][x] != 0 && board[i][x] == board[y][x])
            return false;

    // x axis
    for(int i=0; i<9; ++i)
        if(board[y][i] != 0 && board[y][i] == board[y][x])
            return false;

    // 3 x 3
    for(int yIndex=(y/3)*3, i=0; i<3; ++i)
        for(int xIndex=(x/3)*3, j=0; j<3; ++j)
            if(board[yIndex+i][xIndex+j] != 0 &&
               board[yIndex+i][xIndex+j] == board[y][x])
                return false;

    // pass all condition
    return true;
}

void printBoard(){
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool findAnswer(int y){

    // find answer
    if(y == 9)
        return true;

    for(int x=0; x<9; ++x){
        if(board[y][x] == 0){
            for(int i=1; i<=9; ++i){
                board[y][x] = i;
                if(check(y,x) && findAnswer(y))
                    return true;
                board[y][x] = 0;
            }
        }

        if(x==8)
            findAnswer(y+1);
    }

    return false;
}

int main(){

    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            scanf("%d", &board[i][j]);
        }
    }

    if(findAnswer(0))
        printBoard();

    return 0;
}
