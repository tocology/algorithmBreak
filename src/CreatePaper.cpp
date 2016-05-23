#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > map;
int N;

int paperCnt[2];

int findPaper(int y, int x, int size){
  if(size == 1)
    return map[y][x];
  
  int newSize = size/2;
  
  int topLeft  = findPaper(y, x, newSize);
  int topRight = findPaper(y, x+newSize, newSize);
  int bottomLeft  = findPaper(y+newSize, x, newSize);
  int bottomRight = findPaper(y+newSize, x+newSize, newSize);
  
  // pending check result
<<<<<<< HEAD
  int sum = topLeft + topRight + bottomLeft + bottomRight;
  if(sum == 4 || sum == 0) // all of elements are 1 or 0
    return topLeft;
  
  paperCnt[topLeft]++; paperCnt[topRight]++;
  paperCnt[bottomLeft]++; paperCnt[bottomRight]++;
=======
  if(topLeft != -1 && topRight != -1
     && bottomLeft != -1 && bottomRight != -1){
    int res = topLeft + topRight + bottomLeft + bottomRight;
    if(res == 4 || res == 0)
      return topLeft;
  }
  
  if(topLeft != -1) paperCnt[topLeft]++;
  if(topRight != -1) paperCnt[topRight]++;
  if(bottomLeft != -1) paperCnt[bottomLeft]++;
  if(bottomRight != -1) paperCnt[bottomRight]++;
>>>>>>> 47bd0fd3da9efd67c339c6367bed0ce58d4a1fb6
  
  return -1;
}

int main(){
	
  scanf("%d", &N);
  
  map = vector<vector<int> >(N, vector<int>(N));
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      scanf("%d",&map[i][j]);
  
  paperCnt[0] = paperCnt[1] = 0;
  
  findPaper(0, 0, N);
  
  printf("%d\n%d\n", paperCnt[0], paperCnt[1]);
  
  return 0;
}